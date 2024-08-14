#include <iostream>
#include <vector>

int sumOfDigitSquares(int number) {
    int sum = 0;
    while (number > 0) {
        int digit = number % 10;
        sum += digit * digit;
        number /= 10;
    }
    return sum;
}

int main() {
    int n, m;
    std::cout << "Введите натуральное число n: ";
    std::cin >> n;
    std::cout << "Введите значение m: ";
    std::cin >> m;

    std::vector<int> result;

    for (int i = 1; i < n; i++) {
        if (sumOfDigitSquares(i) == m) {
            result.push_back(i);
        }
    }

    if (result.empty()) {
        std::cout << "Нет натуральных чисел, удовлетворяющих условию." << std::endl;
    } else {
        std::cout << "Натуральные числа, сумма квадратов цифр которых равна " << m << ": ";
        for (int number : result) {
            std::cout << number << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}