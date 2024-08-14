#include <iostream>
#include <vector>

int main() {
    int n;

    // Ввод размерности матрицы
    std::cout << "Введите размерность матрицы n: ";
    std::cin >> n;

    if (n < 3) {
        std::cout << "Размерность матрицы должна быть не менее 3." << std::endl;
        return 1;
    }

    // Создание и инициализация матрицы
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    // Заполнение единицами по бокам
    for (int i = 0; i < n; i++) {
        matrix[i][0] = 1;
        matrix[i][n - 1] = 1;
        matrix[0][i] = 1;
        matrix[n - 1][i] = 1;
    }

    // Вывод матрицы на экран
    std::cout << "Полученная матрица:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
