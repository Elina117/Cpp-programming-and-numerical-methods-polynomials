#include <iostream> 
#include <iomanip> 
#define PI 3.141592653589793
#define e 2.7182818284
#define EPS 0.000001
static double h = 0.2;

static double f(double x) 
{
    double result = 1;
    if (x != 0)
        result = (2/(sqrt(PI)))*pow(e,(-1)*x*x);
    return result;
}

static double Func(double x)
{
    double a = x; 
    double res = x; 
    double q;
    int n = 0; 

    do
    {
        q = ((-1) * x * x * (2 * n + 1) )/ ((2 * n + 3) * (n + 1)); 
        a *= q;
        res += a;
        n++;
    }
    while (abs(a) > EPS);
    return res;
}

static double Left(int n, double x0)
{
    double h = x0 / n; 
    double result = 0;
    double x = 0;
    for (int i = 0; i < n; i++)
    {
        result += h * f(x); 
        x += h;
    }
    return result;
}

static double Central(int n, double x0)
{
    double h = x0 / n;
    double result = 0;
    double x = h / 2;
    for (int i = 0; i < n; i++)
    {
        result += h * f(x); 
        x += h;
    }
    return result;
}

static double Trapezoid(int n, double x0)
{
    double h = x0 / n;
    double result = 0; 
    double x = 0;
    for (int i = 0; i < n; i++)
    {
        result += h * (f(x) + f(x + h)) / 2; 
        x += h;
    }
    return result;
}

static double Simpson(int n, double x0)
{
    double h = x0 / n; 
    double result = 0;
    double x = 0;
    for (int i = 0; i < n; i++)
    {
        result += (f(x) + 4 * f(x + h / 2) + f(x + h)) * h / 6; 
        x += h;
    }
    return result;
}

static double Gauss(int n, double x0)
{
    double h = x0 / n;
    double p1 = (1 - 1.0 / sqrt(3)) * h / 2; 
    double p2 = (1 + 1.0 / sqrt(3)) * h / 2;
    double result = 0;
    double x = 0;
    for (int i = 0; i < n; i++)
    {
        result += (f(x + p1) + f(x + p2)) * h / 2;
        x += h;
    }
    return result;
}

static void J0(double x, double y, double (*calculator)(int, double))
{
    double lastJ = 0; double J = 0;
    int n = 1;
     do
    {
        n *= 2;
        lastJ = J;
        J = calculator(n, x);
    } while (abs(lastJ - J) > EPS); 
    double accuracy = abs(J - y);

    std::cout << x << " " << y << " " << J << " " << accuracy << " " << n << '\n';
}

int main()
{
    double x[11]; 
    double y[11];
    x[0] = 0;  
    y[0] = Func(x[0]);
    for (int i = 1; i < 11; i++)
    {
        x[i] = x[i - 1] + h;
        y[i] = Func(x[i]);
    }

    std::cout << "Left" << '\n'; for (int i = 1; i < 11; i++) 
    {
        J0(x[i], y[i], Left);
    }
    std::cout << "Trapezoid " <<  '\n';
        for (int i = 1; i < 11; i++) 
        {
            J0(x[i], y[i], Trapezoid);
        }
    std::cout << "Simpson " <<  '\n';
        for (int i = 1; i < 11; i++) 
        {
            J0(x[i], y[i], Simpson);
        }
    std::cout << "Gauss" << '\n';
        for (int i = 1; i < 11; i++) 
        {
            J0(x[i], y[i], Gauss);
        }
    std::cout << "Central " << '\n';
        for (int i = 1; i < 11; i++)
        {
            J0(x[i], y[i], Central);
        }
}
