#include <iostream>
#include <vector>

using namespace std;

// int main() {
//     int N;
//     cout << "Введите размерность матрицы : ";
//     cin >> N;

//     vector<vector<double>> matrix(N, vector<double>(N));
//     cout << "Введите элементы матрицы: " << std::endl;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             cin >> matrix[i][j];
//         }
//     }

//     double sum = 0.0;

    
//     for (int g = 0; g < N - 1; g++) {
//         double res = 1;
//         for (int i = 0; i < N - g; i++) {
//             res *= matrix[i][i + g];
//         }
//         sum += res;
//     }

    
//     cout << "Сумма произведений элементов диагональных квадратов: " << sum << std::endl;

//     return 0;
// }

#include <iostream>
#include <vector>

void find_Isomorphic(std::vector<int>& numbers, int N) {
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] != -1) {
            int remainder = numbers[i] % N;
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[j] != -1 && numbers[j] % N == remainder) {
                    numbers[j] = -1;
                }
            }
        }
    }
}

int main() {
    int N;
    std::cout << "Введите N: ";
    std::cin >> N;

    int numElements;
    std::cout << "Введите количество элементов в векторе: ";
    std::cin >> numElements;

    std::vector<int> numbers(numElements);

    std::cout << "Введите элементы вектора: ";
    for (int i = 0; i < numElements; i++) {
        std::cin >> numbers[i];
    }

    find_Isomorphic(numbers, N);

    std::cout << "Результат после удаления изоморфных элементов:" << std::endl;
    int elem = 0;
    if(numbers[elem]!=0)
    {
        double num = numbers[elem];
        cout << num;
    }

    return 0;
}

