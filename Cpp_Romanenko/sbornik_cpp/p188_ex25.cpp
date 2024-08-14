#include <iostream>
#include <string>
#include <ctime>

class Product {
private:
    std::string name;
    double price;
    int year;

public:
    // Конструкторы
    Product() : name(""), price(0.0), year(0) {}

    Product(const std::string& n, double p, int y) : name(n), price(p), year(y) {}

    // Деструктор
    ~Product() {
        std::cout << "Объект " << name << " уничтожен" << std::endl;
    }

    // Метод для определения возраста товара
    int yearsAgo() const {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        return currentYear - year;
    }

    // Метод для увеличения цены, если в наименовании есть слово "TV"
    void increasePriceIfTV() {
        if (name.find("TV") != std::string::npos) {
            price *= 1.2; // Увеличение цены на 20%
        }
    }

    // Метод для формирования строки информации об объекте
    std::string getInfo() const {
        std::string info = "Наименование: " + name + "\n";
        info += "Цена: " + std::to_string(price) + "\n";
        info += "Год выпуска: " + std::to_string(year) + "\n";
        return info;
    }

    int main() {
    Product product1("TV Samsung", 1000.0, 2020);
    Product product2("Laptop HP", 1500.0, 2019);

    // Вывод информации о товарах в компонент Memo
    std::cout << "Информация о товаре 1:\n" << product1.getInfo() << std::endl;
    std::cout << "Информация о товаре 2:\n" << product2.getInfo() << std::endl;

    // Проверка возраста товара
    std::cout << "Товар 1 был выпущен " << product1.yearsAgo() << " лет назад." << std::endl;
    std::cout << "Товар 2 был выпущен " << product2.yearsAgo() << " лет назад." << std::endl;

    // Увеличение цены, если в наименовании есть слово "TV"
    product1.increasePriceIfTV();
    product2.increasePriceIfTV();

    // Вывод обновленной информации о товарах
    std::cout << "Информация о товаре 1 после изменения цены:\n" << product1.getInfo() << std::endl;
    std::cout << "Информация о товаре 2 после изменения цены:\n" << product2.getInfo() << std::endl;

    return 0;
    }

};
