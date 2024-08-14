#include <iostream>
#include <cmath>
#include <vector>

class Circle {
private:
    double centerX;
    double centerY;
    double radius;

public:
    Circle(double x, double y, double r) : centerX(x), centerY(y), radius(r) {}

    // Функция для вычисления расстояния между двумя точками
    double distance(double x1, double y1, double x2, double y2) const {
        return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    // Функция для определения пересечения двух окружностей
    std::vector<std::pair<double, double>> intersect(const Circle& other) const {
        std::vector<std::pair<double, double>> intersectionPoints;

        // Вычисляем расстояние между центрами окружностей
        double dist = distance(centerX, centerY, other.centerX, other.centerY);

        if (dist <= radius + other.radius) {
            // Окружности пересекаются или касаются друг друга
            if (dist == 0 && radius == other.radius) {
                // Окружности совпадают
                intersectionPoints.push_back(std::make_pair(centerX, centerY));
            } else {
                // Окружности пересекаются или касаются в двух точках
                double a = (radius * radius - other.radius * other.radius + dist * dist) / (2 * dist);
                double h = std::sqrt(radius * radius - a * a);

                double x2 = centerX + a * (other.centerX - centerX) / dist;
                double y2 = centerY + a * (other.centerY - centerY) / dist;

                double x3 = x2 + h * (other.centerY - centerY) / dist;
                double y3 = y2 - h * (other.centerX - centerX) / dist;

                double x4 = x2 - h * (other.centerY - centerY) / dist;
                double y4 = y2 + h * (other.centerX - centerX) / dist;

                intersectionPoints.push_back(std::make_pair(x3, y3));
                intersectionPoints.push_back(std::make_pair(x4, y4));
            }
        }

        return intersectionPoints;
    }
};

int main() {
    double x1, y1, r1, x2, y2, r2;
    std::cout << "Введите координаты центра и радиус первой окружности (x, y, r): ";
    std::cin >> x1 >> y1 >> r1;

    std::cout << "Введите координаты центра и радиус второй окружности (x, y, r): ";
    std::cin >> x2 >> y2 >> r2;

    Circle circle1(x1, y1, r1);
    Circle circle2(x2, y2, r2);

    std::vector<std::pair<double, double>> intersectionPoints = circle1.intersect(circle2);

    if (intersectionPoints.empty()) {
        std::cout << "Окружности не пересекаются." << std::endl;
    } else {
        std::cout << "Окружности пересекаются в следующих точках:" << std::endl;
        for (const auto& point : intersectionPoints) {
            std::cout << "Точка (" << point.first << ", " << point.second << ")" << std::endl;
        }
    }

    return 0;
}
