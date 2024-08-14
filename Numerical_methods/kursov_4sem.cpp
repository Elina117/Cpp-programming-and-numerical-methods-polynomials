#include <iostream>
#include <cmath>
using namespace std;
#include <list>

//точные решения
double Met1TOCH(double t) 
{
    return cos(pow(t, 2)) * sqrt(1 + t);
}
double Met2TOCH(double t) 
{
    return sin(pow(t, 2)) * sqrt(1 + t);
}

//правые части диф ур-ий
double Met1(double t, double* y) 
{
    return y[0] / (2 + 2 * t) - 2 * t * y[1];
}
double Met2(double t, double* y)
{
    return y[1]/ (2 + 2 * t) + 2 * t * y[0];
}

//сам метод Рунге - Кутты 4 порядка с шагом h
void RungeKutta(int count, double (**f)(double t, double* y), double** y, double h, int n, double* t, double* y0) 
{
    for (int i = 0;i < count;i++) {
        y[0][i] = y0[i];
    }
    double* k1 = new double[count]();
    double* k2= new double[count]();
    double* k3= new double[count]();
    double* k4= new double[count]();
    for (int i = 0;i < n - 1;i++) 
    {
        for (int j = 0;j < count;j++) 
        {
            k1[j] = f[j](t[i], y[i]);
        }
        double* vectorY = new double[count];
        for (int j = 0;j < count;j++)
        {
            vectorY[j] = y[i][j] + h * k1[j] / 3;
        }
        for (int j = 0;j < count;j++)
        {
            k2[j] = f[j](t[i]+h/3, vectorY);
        }
        for (int j = 0;j < count;j++)
        {
            vectorY[j] = y[i][j] - (h * k1[j] / 3)+(h*k2[j]);
        }
        for (int j = 0;j < count;j++)
        {
            k3[j] = f[j](t[i] + 2*h / 3, vectorY);
        }
        for (int j = 0;j < count;j++)
        {
            vectorY[j] = y[i][j] + (h * k1[j]) - (h * k2[j])+ (h * k3[j]);
        }
        for (int j = 0;j < count;j++)
        {
            k4[j] = f[j](t[i] + h, vectorY);
        }
        delete[] vectorY;
        for (int j = 0;j < count;j++)
        {
            y[i + 1][j] = y[i][j] + h * (k1[j] + 3 * k2[j] + 3 * k3[j] + k4[j]) / 8;
        }
      
    }
    delete[] k1;
    delete[] k2;
    delete[] k3;
    delete[] k4;
}
/// Вычисление погрешности
double Inaccuracy(int numberDivisions, double* t, double** y) {
    double res = 0;
    double currentInaccuracy;
    for (int i = 0; i < numberDivisions; i++) {
        double testy1 = Met1TOCH(t[i]);
        double testy2 = Met2TOCH(t[i]);
        currentInaccuracy = y[i][0] - testy1;
        double otherInaccuracy = y[i][1] - testy2;
        if (otherInaccuracy > currentInaccuracy) currentInaccuracy = otherInaccuracy;
        if (currentInaccuracy > res) res = currentInaccuracy;
        //std::cout << y[i][0] << " " << testy1 << " " << y[i][1] << " " << testy2 << " " << y[i][0] - testy1 << " " << y[i][1] - testy2 << "\n";
    }
    return res;
}

typedef double (*pFunc)(double t, double* y);
//Решает тестовую задачу с заданным числом разбиений и возвращает пару значений: шаг метода и максимальную погрешность.
std::pair<double, double> testTask(int numberDivisions) {
    double h = 2.0 / numberDivisions; //задание шага метода

    double* y1 = new double[numberDivisions]();
    double* y2 = new double[numberDivisions]();
    double* t = new double[numberDivisions];

    for (int i = 0; i < numberDivisions; i++) {
        t[i] = h * i; //создание оси t
    }
    double (**f)(double t, double* y) = new pFunc[2]; //объявление набора функций
    f[0] = Met1;
    f[1] = Met2;
    double** y = new double* [numberDivisions]; //выделение памяти для решения системы
    for (int i = 0; i < numberDivisions; i++) {
        y[i] = new double[2]();
    }
    double* y0 = new (double[2]); //начальные условия
    y0[0] = Met1TOCH(t[0]);
    y0[1] = Met2TOCH(t[0]);
    RungeKutta(2, f, y, h, numberDivisions, t, y0);
    std::pair<double, double> res(h, Inaccuracy(numberDivisions, t, y));
    delete[] y0;
    delete[] y1;
    delete[] y2;
    delete[] t;
    delete[] f;
    for (int i = 0; i < numberDivisions; i++) { //очистка памяти решения системы
        delete[] y[i];
    }
    delete[] y;
    return res;
}

void PrintVectors(double x[],int n,string nameVector) 
{
    std::cout << nameVector;
    std::cout << "=[";
    for (int i = 0; i < n;i++) 
    {
        std::cout << x[i] << "," << " " ;
    }
    std::cout << "];" << "\n";
}

//Выполняет тестовую задачу, вычисляя погрешности для различных шагов метода,
void zadanie_41()
{
    const int n = 100;
    double x[n];
    double y[n];
    for (int i = 0; i < n; i++) {
        std::pair<double, double> inaccuracy = testTask(i + 10);
        x[i] = inaccuracy.first;
        y[i] = inaccuracy.second / pow(x[i], 4);
        //std::cout << inaccuracy.first << "," << inaccuracy.second << "\n";
    }
    PrintVectors(x, n, "x");
    PrintVectors(y, n, "y");
}

double Betta = 0.13;
int gamma = 5;
double X0 = 0.5;
double Y0 = 0.5;
const double alpha=20;
double v=9;

double Met_X(double t, double* y)
{
    return gamma*(1 - y[0])*y[0] - (alpha*y[0]*y[1] / (Betta + y[0]));
}

double Met_Y(double t, double* y)
{
    return (1-(y[1]/y[0]))*y[1];
}
const int numberDivisions = 300;
void predator_prey() {
    double h = v / numberDivisions; //задание шага метода
    double* y1 = new double[numberDivisions]();
    double* y2 = new double[numberDivisions]();
    double* t = new double[numberDivisions];
    for (int i = 0; i < numberDivisions; i++) {
        t[i] = h * i; //создание оси t
    }
    double (**f)(double t, double* y) = new pFunc[2]; //объявление набора функций
    f[0] = Met_X;
    f[1] = Met_Y;
    double** y = new double* [numberDivisions]; //выделение памяти для решения системы
    for (int i = 0; i < numberDivisions; i++) {
        y[i] = new double[2]();
    }
    double* y0 = new (double[2]); //начальные условия
    y0[0] = X0;
    y0[1] = Y0;
    RungeKutta(2, f, y, h, numberDivisions, t, y0);
    double masX[numberDivisions];
    double masY[numberDivisions];
    for (int i = 0; i < numberDivisions; i++) 
    {
        masX[i] = y[i][0];
        masY[i] = y[i][1];
    }
    PrintVectors(masX, numberDivisions, "x");
    PrintVectors(masY, numberDivisions, "y");
    std::cout << "plot(x,y)" << std::endl;


   PrintVectors(t, numberDivisions, "t");
    PrintVectors(masX, numberDivisions, "x");
    std::cout << "plot(t,x)" << std::endl;


   PrintVectors(t, numberDivisions, "t");
    PrintVectors(masY, numberDivisions, "y");
    std::cout << "plot(t,y)" << std::endl;
    delete[] y0;
    delete[] y1;
    delete[] y2;
    delete[] t;
    delete[] f;
    for (int i = 0; i < numberDivisions; i++) { //очистка памяти решения системы
        delete[] y[i];
    }
    delete[] y;  
}

int main()
{
    //тестовая задача  
    const int n = 100;
    double x[n];
    double y[n];
    for (int i = 0; i < n; i++) {
        std::pair<double, double> inaccuracy = testTask(i+10);
        x[i] = inaccuracy.first;
        y[i] = inaccuracy.second;
       //std::cout << inaccuracy.first << "," << inaccuracy.second << "\n";
    }
    PrintVectors(x,n,"x");
    PrintVectors(y,n,"y");
    zadanie_41();
    ////задача
   predator_prey();
}