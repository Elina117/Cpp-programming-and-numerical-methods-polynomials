#include <iostream>
#include <string>

// Класс 1-го уровня - Алмаз
class Diamond {
protected:
    std::string name;
    double weight;
    int cutQuality;

public:
    Diamond(const std::string& n, double w, int cq) : name(n), weight(w), cutQuality(cq) {}

    double calculateQuality() {
        // Формула для качества Q класса 1-го уровня
        return 0.4 * weight + 0.6 * cutQuality;
    }

    void printInfo() {
        std::cout << "Diamond Info - Name: " << name << ", Weight: " << weight << " carats, Cut Quality: " << cutQuality << " points" << std::endl;
    }
};

// Класс 2-го уровня - Алмаз с учетом цвета
class ColoredDiamond : public Diamond {
private:
    std::string color;

public:
    ColoredDiamond(const std::string& n, double w, int cq, const std::string& col) : Diamond(n, w, cq), color(col) {}

    double calculateQuality() {
        double Q = Diamond::calculateQuality(); // Вызов функции качества из класса-родителя

        // Формула для качества Qp класса 2-го уровня в зависимости от цвета
        if (color == "blue") {
            return Q + 1;
        } else if (color == "yellow") {
            return Q - 0.5;
        } else {
            return Q;
        }
    }

    void printInfo() {
        std::cout << "Colored Diamond Info - Name: " << name << ", Weight: " << weight << " carats, Cut Quality: " << cutQuality << " points, Color: " << color << std::endl;
    }
};

int main() {
    // Создание объекта класса 1-го уровня - Алмаз
    Diamond diamond("Diamond 1", 5.2, 80);
    std::cout << "Quality of Diamond: " << diamond.calculateQuality() << std::endl;
    diamond.printInfo();

    // Создание объекта класса 2-го уровня - Алмаз с учетом цвета
    ColoredDiamond coloredDiamond("Diamond 2", 4.7, 90, "blue");
    std::cout << "Quality of Colored Diamond: " << coloredDiamond.calculateQuality() << std::endl;
    coloredDiamond.printInfo();

    return 0;
}
