#include <iostream>
#include <string>
#include <map>

struct Product {
    std::string name;
    int quantity;

    Product(const std::string& productName, int productQuantity) {
        name = productName;
        quantity = productQuantity;
    }
};

int main() {
    int numProducts;
    std::cout << "Введите количество товаров: ";
    std::cin >> numProducts;

    std::map<std::string, int> productMap;

    for (int i = 0; i < numProducts; i++) {
        std::string name;
        int quantity;

        std::cout << "Введите название товара: ";
        std::cin >> name;

        std::cout << "Введите количество проданного товара: ";
        std::cin >> quantity;

        // Проверяем, есть ли уже такой товар в карте, и обновляем количество
        productMap[name] += quantity;
    }

    std::cout << "Сгруппированные записи по названию товара и суммарное количество:" << std::endl;
    for (const auto& pair : productMap) {
        std::cout << "Название товара: " << pair.first << std::endl;
        std::cout << "Суммарное количество: " << pair.second << std::endl;
    }

    return 0;
}
