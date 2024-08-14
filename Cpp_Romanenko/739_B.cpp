#include <iostream>
#include <vector>

// Функция для вывода матрицы и вектора
void printMatrix(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector) {
    int n = vector.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "| " << vector[i] << "\n";
    }
}

// Функция для решения системы методом Гаусса
std::vector<double> gauss(std::vector<std::vector<double>> matrix, std::vector<double> vector) {
    int n = vector.size();

    // Прямой ход метода Гаусса
    for (int pivot = 0; pivot < n; ++pivot) {
        // Находим максимальный элемент в текущем столбце и перемещаем его на позицию pivot
        int maxRow = pivot;
        for (int row = pivot + 1; row < n; ++row) {
            if (std::abs(matrix[row][pivot]) > std::abs(matrix[maxRow][pivot])) {
                maxRow = row;
            }
        }
        std::swap(matrix[pivot], matrix[maxRow]);
        std::swap(vector[pivot], vector[maxRow]);

        // Обнуляем все элементы ниже текущего pivot
        for (int row = pivot + 1; row < n; ++row) {
            double factor = matrix[row][pivot] / matrix[pivot][pivot];
            vector[row] -= factor * vector[pivot];
            for (int col = pivot; col < n; ++col) {
                matrix[row][col] -= factor * matrix[pivot][col];
            }
        }
    }

    // Обратный ход метода Гаусса
    std::vector<double> solution(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (vector[i] - sum) / matrix[i][i];
    }

    return solution;
}

int main() {
    std::vector<std::vector<double>> matrix = {{6.0, -1.0, -1.0},
                                               {-1.0, 6.0, -1.0},
                                               {-1.0, -1.0, 6.0}};
    std::vector<double> vector = {11.33, 32.0, 15.0};

    std::vector<double> solution = gauss(matrix, vector);

    std::cout << "Решение системы уравнений:\n";
    for (size_t i = 0; i < solution.size(); ++i) {
        std::cout << "x" << i + 1 << " = " << solution[i] << "\n";
    }

    return 0;
}
