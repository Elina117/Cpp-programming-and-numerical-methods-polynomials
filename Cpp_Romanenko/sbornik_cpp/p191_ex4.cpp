#include <iostream>
#include <string>

// Класс-родитель
class Product {
protected:
    std::string name;
    double price;

public:
    Product(std::string productName, double productPrice) : name(productName), price(productPrice) {}

    void displayInfo() {
        std::cout << "Product: " << name << ", Price: " << price << std::endl;
    }
};

// Класс-потомок
class VitaminCProduct : public Product {
private:
    double vitaminCPerGram;

public:
    VitaminCProduct(std::string productName, double productPrice, double vitaminC) : Product(productName, productPrice), vitaminCPerGram(vitaminC) {}

    double processData() {
        
        double totalVitaminC = vitaminCPerGram * 100; // Пример для 100 грамм продукта
        return totalVitaminC;
    }

    void displayInfo() {
        Product::displayInfo();
        std::cout << "Vitamin C per gram: " << vitaminCPerGram << std::endl;
    }
};

int main() {
    // Создание объекта класса-родителя
    Product product1("Apple", 2.0);
    product1.displayInfo();

    // Создание объекта класса-потомка
    VitaminCProduct vitaminCProduct("Orange", 3.0, 50); // Предположим, 50 мг витамина C в 1 грамме
    vitaminCProduct.displayInfo();

    // Обработка данных для класса-потомка
    double totalVitaminCAmount = vitaminCProduct.processData();
    std::cout << "Total Vitamin C in product: " << totalVitaminCAmount << " mg" << std::endl; // Вывод обработанных данных

    return 0;
}
