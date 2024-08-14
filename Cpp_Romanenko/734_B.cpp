#include <iostream>
#include <cmath>

double func(double x) {
    return x * x * x - 1.75 * x + 0.75;
}

double findRoot(double a, double b, double epsilon) {
    double c;
    while ((b - a) >= epsilon) {
        c = (a + b) / 2.0;
        if (func(c) == 0.0)
            return c;
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2.0;
}

int main() {
    double a = 0.0; // Левая граница интервала
    double b = 1.0; // Правая граница интервала
    double epsilon = 0.0001; // Точность

    double root = findRoot(a, b, epsilon);
    std::cout << "Наименьший корень: " << root << std::endl;

    return 0;
}
