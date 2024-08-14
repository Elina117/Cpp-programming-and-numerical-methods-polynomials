#include <iostream>
#include <set>
#include <vector>

int main() {
    int n;
    std::cout << "Введите количество элементов в последовательности: ";
    std::cin >> n;

    std::vector<int> sequence(n);
    std::cout << "Введите элементы последовательности: ";
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    // Используем std::set для хранения уникальных элементов
    std::set<int> uniqueElements;

    // Перебираем элементы последовательности и добавляем их в std::set
    for (int i = 0; i < n; i++) {
        uniqueElements.insert(sequence[i]);
    }

    // Получаем количество уникальных элементов
    int countOfUniqueElements = uniqueElements.size();

    std::cout << "Количество различных элементов в последовательности: " << countOfUniqueElements << std::endl;

    return 0;
}