#include <iostream>
#include <cmath>
#include <vector>

int main() {
    
    double power = std::pow(2, -200);

    int k = 0;
    double sum_of_num = power;
    while (sum_of_num <= 1.0) {
        sum_of_num *= 10;
        k++;
    }

    // Создаем вектор для хранения цифр
    std::vector<int> digits;

    // Извлекаем цифры
    for (int i = 0; i < k; i++) {
        int digit = static_cast<int>(sum_of_num); //извлекается целая часть 
        digits.push_back(digit);
        sum_of_num -= digit;
        sum_of_num *= 10;
    }

    // Выводим полученные цифры
    std::cout << "Цифры числа 2^-200: ";
    for (int digit : digits) {
        std::cout << digit;
    }
    std::cout << std::endl;

    return 0;
}

