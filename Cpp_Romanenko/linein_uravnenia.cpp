#include <stdio.h>
#include <iostream>
#include <cmath>


//2
double f2(double x)
{
    double res = x*log(x)-2;
    return res;
}
//1–
double f1(double x)
{
    double fun = sin(x)-pow(x, 3) -1;
    return fun;
}

double bisection(double (*func)(double), double a, double b, double e)
{
    if(func(a)*func(b)>=0)
    {
        std::cout << "Error";
    }
    
    
        double c;
        int iterations = 0;

        while((b-a)>e)
        {
            c = (a+b)/2;

            if(func(c)==0)
            {
                break; //on the left side
            }
            else if(func(a)*func(b)<0)
            {
                b=c;
            }
            else
            {
                a=c;
            }
            iterations++;
        }
        return c;
    
        
}

int main()
{
    //second function
    double a_1 = 2;
    double b_1 = 3;
    double e_1 = 2.34575;
    double x_1;

    double root1 = bisection(f1, a_1, b_1, e_1);
    if (root1 != 0) 
    {
        std::cout << "Приближенный корень для Sin(x) = x^3 + 1: " << root1;
    } 
    else 
    {
        std::cout << "Корень для Sin(x) = x^3 + 1 не найден.";
    }

    double a_2;
    double b_2;
    double e_2;
    double x_2;
    std::cout << "Введите левую границу";
    std::cin >> a_2;

    std::cout << "Введите правую границу";
    std::cin >> b_2;
    
    double root2 = bisection(f2, a_2, b_2, e_2);
    if(root2!=0)
    {
        std::cout << "Приближенный корень для xln(x) - 2 = 0: " << root2;
    } 
    else 
    {
        std::cout << "Корень для xln(x) - 2 = 0 не найден.";
    }
    
}

