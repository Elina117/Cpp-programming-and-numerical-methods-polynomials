#include <iostream>
#include <cmath>

// Функция для вычисления косинуса угла alpha для заданного значения x
double calculateCosAlpha(double x) {
    return (x * x - 2 * x - 3) / (2 * x * (x + 1));
}

int main() {
    const int numPoints = 80; // Количество точек на графике
    const double startX = (-sqrt(37.0) - 1) / 6; // Начальное значение x
    const double endX = (sqrt(37.0) - 1) / 6; // Конечное значение x
    const double step = (endX - startX) / numPoints; // Шаг изменения x

    for (double x = startX; x <= endX; x += step) {
        double cosAlpha = calculateCosAlpha(x);
        int scaledCosAlpha = static_cast<int>((cosAlpha + 1) * 40); 
        for (int i = 0; i < scaledCosAlpha; ++i) {
            std::cout << " "; // Пробелы для пустых мест на графике
        }
        std::cout << "*\n"; // Звездочка для представления точки на графике
    }

    return 0;
}
