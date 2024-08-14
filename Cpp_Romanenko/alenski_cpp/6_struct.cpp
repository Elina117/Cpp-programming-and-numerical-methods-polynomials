#include <iostream>
#include <cstring>
#include <vector>

struct Product {
    char name[100];
    int cost;
    int price;

    Product(const char* productName, int productCost, int productPrice) {
        strncpy(name, productName, sizeof(name));
        cost = productCost;
        price = productPrice;
    }

    // Функция для вычисления рентабельности
    float calculateProfitability() const 
    {
        return static_cast<float>(price - cost) / cost;
    }
};

// Функция для вывода информации о товарах с заданной рентабельностью
void printProductsByProfitability(const std::vector<Product>& products, float targetProfitability) {
    std::cout << "Товары с рентабельностью более " << targetProfitability << ":" << std::endl;
    for (const Product& product : products) {
        if (product.calculateProfitability() > targetProfitability) {
            std::cout << "Название: " << product.name << std::endl;
            std::cout << "Себестоимость: " << product.cost << std::endl;
            std::cout << "Цена реализации: " << product.price << std::endl;
            std::cout << "Рентабельность: " << product.calculateProfitability() << std::endl;
        }
    }
}

int main() {
    int numProducts;
    std::cout << "Введите количество товаров: ";
    std::cin >> numProducts;

    std::vector<Product> products;

    for (int i = 0; i < numProducts; i++) {
        char name[100];
        int cost, price;

        std::cout << "Введите название товара: ";
        std::cin.ignore();
        std::cin.getline(name, sizeof(name));

        std::cout << "Введите себестоимость товара: ";
        std::cin >> cost;

        std::cout << "Введите цену реализации товара: ";
        std::cin >> price;

        products.emplace_back(name, cost, price);
    }

    float targetProfitability;
    std::cout << "Введите минимальное значение рентабельности: ";
    std::cin >> targetProfitability;

    printProductsByProfitability(products, targetProfitability);

    return 0;
}
