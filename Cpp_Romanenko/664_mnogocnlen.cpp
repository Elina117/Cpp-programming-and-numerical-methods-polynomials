#include <iostream>
#include <vector>

int main() {
    int n; // Степень многочлена P(x)
    double s, t; 
    std::vector<double> P; // Коэффициенты многочлена P(x)
    
    std::cout << "Введите степень многочлена P(x): ";
    std::cin >> n;

    std::cout << "Введите коэффициенты многочлена P(x) (начиная с коэффициента при x^0 и заканчивая коэффициентом при x^" << n << "): ";
    for (int i = 0; i <= n; i++) {
        double coefficient;
        std::cin >> coefficient;
        P.push_back(coefficient);
    }

    std::cout << "Введите значение s: ";
    std::cin >> s;

    std::cout << "Введите значение t: ";
    std::cin >> t;

    // Вычисление производной многочлена P(x)
    std::vector<double> P_prime(n); // Массив для коэффициентов производной P'(x)
    for (int i = 0; i < n; i++) {
        P_prime[i] = (i + 1) * P[i + 1]; 
    }

    // Умножение многочлена P(x) на (s*x^2 + t)
    std::vector<double> result(n + 3); // Результат будет многочленом степени n + 2
    for (int i = 0; i <= n; i++) {
        result[i + 2] = s * P[i]; // Умножаем каждый коэффициент P(x) на s и сдвигаем вправо на 2
    }
    
    // Добавление P'(x) к результату
    for (int i = 0; i <= n; i++) {
        result[i] += P_prime[i];
    }

    // Вывод результата
    std::cout << "Результат многочлена (s*x^2 + t)*P(x) + P'(x): ";
    for (int i = 0; i <= n + 2; i++) {
        std::cout << result[i] << "x^" << i;
        if (i < n + 2) {
            std::cout << " + ";
        }
    }
    std::cout << std::endl;

    return 0;
}
