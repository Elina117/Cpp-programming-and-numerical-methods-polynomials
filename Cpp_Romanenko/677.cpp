#include <iostream>
#include <vector>

int main() {
    int n; // Размерность матрицы
    std::cout << "Введите размерность матрицы (n): ";
    std::cin >> n;

    // Создание и инициализация исходной матрицы aij
    std::vector<std::vector<double>> aij(n, std::vector<double>(n));
    std::cout << "Введите элементы матрицы aij:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> aij[i][j];
        }
    }

    // Создание и инициализация матрицы bij
    std::vector<std::vector<double>> bij(n, std::vector<double>(n));

    // Вычисление матрицы bij
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int x = 0; x <= i; x++) {
                for (int y = 0; y <= j; y++) {
                    sum += aij[x][y];
                }
            }
            bij[i][j] = sum;
        }
    }

    // Вывод матрицы bij
    std::cout << "Матрица bij:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << bij[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
