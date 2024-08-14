#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

const double PI = 3.141592653589793;
double a = 0;
double b = 2;
double m = 11;
//функция через приближенные суммы
double define_sum(double x, double e = pow(10, -6))
{
    double q_n = (-pow(x, 2))/3;
    double a_0 = x;

    double sum_row = a_0;

    int n = 1;

    while (abs(a_0)>e)
    {
        a_0 = q_n*a_0;
        q_n = ((-1)*pow(x, 2)*(2*n+1))/((n+1)*(2*n+3));

        sum_row += a_0;

        n++;
 
    }
   
    sum_row*=(2/pow(PI, 0.5));
    
    return sum_row;
    
}
//функция по Лагранжу
double L_n(double x, vector<double> list_x) 
{

    double sum = 0;

    for (int i = 0; i < list_x.size(); i++) {
        double x_i = list_x[i];
        double mult_x = 1;

        for (int j = 0; j < list_x.size(); j++) {
            if (i == j) {
                continue; 
            }

            mult_x *= (x - x_i) / (x_i - list_x[j]);
        }

        sum += define_sum(x_i) * mult_x;
    }

    return sum;
}

//вывод таблицы с погршеностями Лагранжа для 11 точек
void table_of_interpolation_error()
{
    
    double h = (b-a)/5;
    double x = a; //табулирование

    vector<double> list_x;

    while(x<=b)
    {
        list_x.push_back(x);
        x+=h;
    }

    double h_ = (b-a)/m;
    double max_diff = 0;
    
    for(int i = 0; i<=m; i++)
    {
        double x_i = i*h_;
        double Ln = L_n(x_i, list_x);
        double erf_x = define_sum(x_i);

        max_diff = max(abs(Ln-erf_x), max_diff);

        cout << "x(" << i << ") : " << x_i << ";" << "Значение L_n(x_" << i << ") : " << Ln << ";" << "Погрешность интерполяции: " << abs(erf_x-Ln) << "\n";

    }

    cout << "Максимальная разница: " << max_diff;
}

//функция выбора узлов(точек) в зависимости от шага и количества
vector<double> points_equally_distributed(int cnt)
{
    double h = (b - a)/cnt;
    double x = 0;

    vector<double> list_x;

    while(x<=b)
    {
        list_x.push_back(x);
        x+=h;
    }

    return list_x;

}

//функция выбора узлов для Чебышева
vector<double> chebyshev_nodes(int cnt)
{
    int k = 0;
    vector<double> nodes;

    while(k<=cnt)
    {
        int x_k = 0.5 * (a+b) + 0.5 * (b-a) * cos((2*k+1)*PI/(2*k+2));
        nodes.push_back(x_k);
        k++;
    }
    
    return nodes;
}

int main()
{
    //выводит сумму для 6 узлов
    double h = (b-a)/5;
    double x = a; //табулирование

    vector<double> list_x;

    while(x<=b)
    {
        list_x.push_back(x);
        x+=h;
    }
    for (int i = 0; i < list_x.size(); i++)
    {
        cout << "sum(" << list_x[i] << ") = " << define_sum(list_x[i]) << endl;
    }


    // эксперемент с разным количеством узлов, точки равнораспределены
    double h_ = (b-a)/m;
    double max_diff = 0;

    vector<double> ln_s;
    vector<double> fx_s;
    vector<double> x_si;
   

    map<int, double> dict_of_diff_values_equaly;
    
    for(int counter = 7; counter<62; counter++)
    {
        for (int i = 0; i < m; i++)
        {
            double x_i = h_*i;
            x_si.push_back(x_i);
            double Ln = L_n(x_i, points_equally_distributed(counter));
            ln_s.push_back(Ln);
            double fx = define_sum(x_i);
            fx_s.push_back(fx);

            max_diff = max(abs(Ln-fx), max_diff);
            dict_of_diff_values_equaly[counter] = max_diff;
          
        }

        cout << "Количество равнораспределенных узлов: " << counter << "  Максимальная разница: " << max_diff << "\n";
    }
    

    //эксперемент с узлыми Чебышева
    vector<double> ln_k;
    vector<double> fx_k;
    vector<double> x_ki;

    map<int, double> dict_of_diff_values_cheb;

    for(int counter = 0; counter<15; counter++)
    {
        for (int k = 0; k < m; k++)
        {
            double x_k = h_*k;
            x_ki.push_back(x_k);
            double Ln_k = L_n(x_k, chebyshev_nodes(counter));
            ln_k.push_back(Ln_k);
            double fx = define_sum(x_k);
            fx_k.push_back(fx);

            max_diff = max(abs(Ln_k-fx), max_diff);
            dict_of_diff_values_cheb[counter] = max_diff;
          
        }

        cout << "Количество узлов Чебышева: " << counter << "  Максимальная разница: " << max_diff << "\n";
    }
    
}