#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
//функция приюлиженных сумм
double define_sum(double x, double e = pow(10, -6))
{
    const double PI = 3.141592653589793;
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
//метод Лагранжа
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

            mult_x *= (x - list_x[j]) / (x_i - list_x[j]);
        }

        sum += define_sum(x_i) * mult_x;
    }

    return sum;
}
//тыблица вывода интерполяционной погршености, erf(x)
void table()
{
    double a = 0;
    double b = 2;
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

    double m = 10;
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

//вычисление узлов Чебышева
vector<double> points_cheb(int cnt)
{

    double a = 0;
    double b = 2;
    vector<double> nodes;
    const double PI = 3.141592653589793;
    
    for (int i = 0; i < cnt; i++)
    {
        double x_k = 0.5 * (a + b) + 0.5 * (b - a) * cos((2 * i + 1) * PI / (2 * cnt+2));
        nodes.push_back(x_k);
    }
    
    return nodes;


}

void cheb_table()
{
    int m = 10;
    vector<double> list_x = points_cheb(m);
    double max_diff = 0;
    
    for(int i = 0; i<=m; i++)
    {
        double x_i = list_x[i];
        double Ln = L_n(x_i, list_x);
        double erf_x = define_sum(x_i);

        max_diff = max(abs(Ln-erf_x), max_diff);

        cout << "x(" << i << ") : " << x_i << ";" << "Значение L_n(x_" << i << ") : " << Ln << ";" << "Погрешность интерполяции: " << abs(erf_x-Ln) <<  "Erf(x):" << erf_x << "\n";

    }

    cout << "Максимальная разница: " << max_diff;
}
//вычисление равнораспределенных узлов
vector<double> points_equally_distributed(int cnt)
{
    double a =0;
    double b = 2;
    double h = (b-a)/cnt;
    double x = a;
    vector<double> list_x;

    while(x<=b)
    {
        list_x.push_back(x);
        x+=h;
    }

    return list_x;
}
//эксперемент 1 с равнораспределенными узлами
void exp1()
{
    double a = 0;
    double b = 2;
    double m = 10;
    double h_ = (b-a)/m;
    double max_diff = 0;

    vector<double> ln_s;
    vector<double> fx_s;
    vector<double> x_si;
   

    map<int, double> dict_of_diff_values_equaly;
    
    for(int counter = 7; counter<35; counter++)
    {
        if(counter%10==0)
        {
            continue;
        }
        for (int i = 0; i <= m; i++)
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
}

//эксперемент 2 с узлами Чебышева
void exp2()
{
    double max_diff = 0;
    double m = 10;
    double a =0;
    double b = 2;
    double h_ = (b-a)/m;

    vector<double> ln_k;
    vector<double> fx_k;
    vector<double> x_ki;

    map<int, double> dict_of_diff_values_cheb;

    for(int counter = 1; counter<16; counter++)
    {
        double max_diff = 0;
        for (int k = 0; k < m; k++)
        {
            double x_k = h_*k;
            x_ki.push_back(x_k);
            double Ln_k = L_n(x_k, points_cheb(counter));
            ln_k.push_back(Ln_k);
            double fx = define_sum(x_k);
            fx_k.push_back(fx);

            max_diff = max(abs(Ln_k-fx), max_diff);
            dict_of_diff_values_cheb[counter] = max_diff;
          
        }

        cout << "Количество узлов Чебышева: " << counter << "  Максимальная разница: " << max_diff << "\n";
    }
}

int main()
{
    table(); // таблица
    cheb_table();
    exp1(); // эксперемент 1
    exp2(); // эксперемент 2 
}