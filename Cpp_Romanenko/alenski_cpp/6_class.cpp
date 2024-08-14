#include <iostream>
#include <vector>

class SquareMatrix {
private:
    std::vector<std::vector<int>> matrix;
    int size; // Размерность квадратной матрицы

public:
    // Конструктор класса
    SquareMatrix(int n) : size(n) 
    {
        matrix.resize(n, std::vector<int>(n, 0)); // Инициализация нулевой матрицей
    }

    // Метод для ввода матрицы
    void inputMatrix() {
        std::cout << "Введите элементы матрицы " << size << "x" << size << ":" << std::endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cin >> matrix[i][j];
            }
        }
    }

    // Метод для сложения матриц
    SquareMatrix add(const SquareMatrix& other) const {
        if (size != other.size) {
            throw std::runtime_error("Невозможно сложить матрицы разных размеров.");
        }
        SquareMatrix result(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }

        return result;
    }

    // Метод для вычитания матриц
    SquareMatrix subtract(const SquareMatrix& other) const {
        if (size != other.size) {
            throw std::runtime_error("Невозможно вычесть матрицы разных размеров.");
        }
        SquareMatrix result(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }

        return result;
    }

    // Метод для перемножения матриц
    SquareMatrix multiply(const SquareMatrix& other) const {
        if (size != other.size) {
            throw std::runtime_error("Невозможно перемножить матрицы разных размеров.");
        }
        SquareMatrix result(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        return result;
    }

    // Метод для вывода матрицы
    void displayMatrix() const {
        std::cout << "Результат:" << std::endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int n;
    std::cout << "Введите размерность квадратной матрицы: ";
    std::cin >> n;

    SquareMatrix matrixA(n);
    SquareMatrix matrixB(n);

    std::cout << "Матрица A:" << std::endl;
    matrixA.inputMatrix();

    std::cout << "Матрица B:" << std::endl;
    matrixB.inputMatrix();

    try {
        SquareMatrix sum = matrixA.add(matrixB);
        sum.displayMatrix();

        SquareMatrix difference = matrixA.subtract(matrixB);
        difference.displayMatrix();

        SquareMatrix product = matrixA.multiply(matrixB);
        product.displayMatrix();
    } 
    catch (std::runtime_error& e) 
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
