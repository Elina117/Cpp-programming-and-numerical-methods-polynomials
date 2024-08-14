#include <iostream>
#include <string>
#include <ctime>

// Класс-родитель
class Book {
public:
    // Поля класса-родителя
    std::string title;
    std::string author;
    int year;

    // Конструктор класса-родителя
    Book(std::string t, std::string a, int y) : title(t), author(a), year(y) {}
};

// Класс-потомок
class BookStore : public Book {
public:
    // Поле класса-потомка
    double price;

    // Конструктор класса-потомка
    BookStore(std::string t, std::string a, int y, double p) : Book(t, a, y), price(p) {}

    // Метод обработки данных объекта класса-потомка
    void decreasePrice() {
        // Получаем текущий год
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        int currentYear = timePtr->tm_year + 1900;

        // Проверяем, прошло ли более 5 лет с года издания книги
        if (currentYear - year > 5) {
            // Уменьшаем цену на 20%
            price *= 0.8; // Уменьшаем на 20%
            std::cout << "Цена книги после снижения: " << price << std::endl;
        } else {
            std::cout << "Книге меньше 5 лет, снижение цены не производится." << std::endl;
        }
    }
};

int main() {
    // Создаем объект класса-потомка
    BookStore bookStore("Book Title", "Book Author", 2010, 50.0);

    // Вызываем метод для уменьшения цены книги
    bookStore.decreasePrice();

    return 0;
}
