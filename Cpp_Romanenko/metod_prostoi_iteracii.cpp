#include <stdio.h>
#include <iostream>
#include <cmath>


//function
double f_1(double x)
{
    return exp(x)-4*x*x;
}

double f_2(double x)
{
    return cos(x)- 3*x+1;
}

//function for iterations
double g_1(double x)
{
    return log(4*x*x);
}

double g_2(double x)
{
    return (cos(x)-1)/3;
}
int main()
{
    const double epsilon = pow(10, -5); //эпсилон
    double x0 = 4.5; //начальное приближение

    int maxIter = 1000000; //максимальное число итераций

    for(int i = 0; i <maxIter; i++)
    {
        double x1 = g_1(x0);

        if(abs(x1-x0)<epsilon) //проверяем точность
        {
            std::cout << "Решение e^x - 4*x^2 = 0 найдено: " << x1;
            break;
        }
        x0 = x1;
    }

  
    double x0_0 = 3.5;

    for(int j = 0; j <maxIter; j++)
    {
        double x1 = g_2(x0_0);
        std::cout << x1;
        if(abs(x1-x0_0)<epsilon) //проверяем точность
        {
            std::cout << "Решение cos(x) = 3*x+1 найдено: " << x1;
            break;
        }
        x0_0 = x1;
    }

}