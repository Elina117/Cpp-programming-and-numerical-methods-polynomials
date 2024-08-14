#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return sqrt(4 + x * x);
}

//метод средних прямоугольников

/*на разбивает интервал [a, b] на более мелкие подинтервалы, 
вычисляет значение функции в средней точке каждого подинтервала и 
умножает это значение на ширину подинтервала h, а затем складывает результаты. 
Процесс повторяется с удвоением числа подинтервалов до тех пор, пока разница между двумя 
последовательными оценками интеграла не станет меньше epsilon.*/
double calculate_integral(double a, double b, double epsilon) {
    double h, integral = 0, prev_integral = 0;
    int n = 1;

    do 
    {
        prev_integral = integral;
        integral = 0;
        h = (b - a) / n;

        for (double x = a + h / 2; x < b; x += h) {
            integral += func(x) * h;
        }

        n *= 2;
    } 
    while (abs(integral - prev_integral) >= epsilon);

    return integral;
}

int main() {
    double a = 0;
    double b = 3;
    double epsilon;

    cout << "Введите значение эпсилон (желаемой точности): ";
    cin >> epsilon;

    double result = calculate_integral(a, b, epsilon);

    cout << "Вычисленный интеграл с точностью " << epsilon << " равен: " << result << endl;

    return 0;
}
