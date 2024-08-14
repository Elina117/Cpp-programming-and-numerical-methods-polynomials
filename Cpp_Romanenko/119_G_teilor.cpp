#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    double e = 0.000001;
   
    double a_0 = 1;
    double q_n;
    double sum_row = a_0;

    int n = 0;

    while (abs(a_0) > e) {
        q_n = -2.0 / (n + 1); // Приведем числитель к типу double для правильных вычислений
        cout << "q_n: " << q_n << endl;

        a_0 = q_n * a_0;
        cout << "a_0: " << a_0 << endl;

        sum_row += a_0;
        cout << "sum_row: " << sum_row << endl;

        n++;
    }
    
    return 0;
}

// int main()
// {
//     double e = 0.000001;
   
//     double a_0 = 1;
//     double q_n;
//     double sum_row = a_0;

//     int n = 0;

//     while (abs(a_0)>e)
//     {
//         q_n = (-2)/(n+1);
//         cout << "Выводим Q_n "<< q_n;
//         a_0 = q_n*a_0;
//         cout << "Выводим А0" <<a_0;
        

//         sum_row += a_0;

//         n++;
//         cout << "Выводим сумму"<< sum_row;
 
//     }
    
    
    
    
//     return 0;
// }

