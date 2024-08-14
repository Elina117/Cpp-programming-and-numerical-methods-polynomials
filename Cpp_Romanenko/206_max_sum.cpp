#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cout << "Введите натуральное число n: ";
    std::cin >> n;

    double max_value = 0.0;
    double sum = 0.0;

    for (int k = 1; k <= n; k++) {
        double value = k * std::exp(std::sin(k + 1));
        
        // Проверяем наибольшее значение
        if (value > max_value) {
            max_value = value;
        }

        // Добавляем значение к сумме
        sum += value;
    }

    std::cout << "Наибольшее значение: " << max_value << std::endl;
    std::cout << "Сумма всех значений: " << sum << std::endl;

    return 0;
}