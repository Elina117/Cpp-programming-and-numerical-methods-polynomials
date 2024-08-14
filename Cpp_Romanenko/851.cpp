#include <iostream>
#include <cmath>

const double PI = 3.14159;

int main() {
    const int numPoints = 150; // Количество точек на спирали
    const double alpha = PI / 6.0; // Начальный угол alpha
    const int n = 3; // Количество витков
    const double startT = alpha; // Начальное значение параметра t
    const double endT = 2 * PI * n; // Конечное значение параметра t
    const double step = (endT - startT) / numPoints; // Шаг изменения параметра t

    for (double t = startT; t <= endT; t += step) {
        double r = t / (2 * PI * n); // Изменение радиуса для увеличения скорости закручивания
        double x = r * cos(t);
        double y = r * sin(t);
        
        // Масштабирование для отображения в консоли
        int scaledX = static_cast<int>(x * 20) + 40; // Сдвигаем вправо на 40 позиций
        int scaledY = static_cast<int>(y * 20) + 20; // Сдвигаем вниз на 20 позиций

        for (int i = 0; i < scaledX; ++i) {
            std::cout << " "; // Пробелы для пустых мест на графике
        }
        for (int i = 0; i < scaledY; ++i) {
            std::cout << "*"; // Звездочки для представления точек на спирали
        }
        std::cout << std::endl;
    }

    return 0;
}
