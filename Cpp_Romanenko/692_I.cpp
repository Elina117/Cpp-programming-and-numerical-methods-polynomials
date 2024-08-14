#include <iostream>
#include <limits>

using namespace std;

const int MAX_SIZE = 100;

int findMaxInStripedPart(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int maxElement = numeric_limits<int>::min();

    // Обход верхнего левого треугольника
    for (int i = 0; i < (n/2); ++i) {
        for (int j = 0; j <= i; ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
            }
        }
    }

    

    return maxElement;
}

int main() {
    int n;

    cout << "Введите порядок матрицы: ";
    cin >> n;

    if (n <= 0 || n > MAX_SIZE) {
        cerr << "Ошибка: некорректный порядок матрицы\n";
        return 1;
    }

    int matrix[MAX_SIZE][MAX_SIZE];

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int maxInStripedPart = findMaxInStripedPart(matrix, n);

    cout << "Наибольший элемент в заштрихованной части: " << maxInStripedPart << endl;

    return 0;
}
