#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <climits>

struct ExamResult {
    std::string examDate;       // Дата экзамена
    std::string fullName;       // ФИО сдававшего
    std::string startTime;      // Время начала теста
    std::string endTime;        // Время окончания теста
    int correctAnswers;         // Количество правильных ответов
};

// Функция для сортировки по дате
bool compareDates(const ExamResult& a, const ExamResult& b) {
    return a.examDate < b.examDate;
}

int main() {
    std::vector<ExamResult> results;  // Вектор для хранения результатов экзаменов

    // Ввод данных о сдаче экзамена
    ExamResult result1, result2, result3;

    // Добавление результатов в вектор
    result1.examDate = "01112021";
    result1.fullName = "Петров Иван Петрович";
    result1.startTime = "09:00:00";
    result1.endTime = "09:30:00";
    result1.correctAnswers = 19;

    result2.examDate = "04112021";
    result2.fullName = "Сидорова Ольга Владимировна";
    result2.startTime = "14:30:00";
    result2.endTime = "15:15:00";
    result2.correctAnswers = 16;

    result3.examDate = "27102021";
    result3.fullName = "Козлов Алексей Николаевич";
    result3.startTime = "11:00:00";
    result3.endTime = "11:30:00";
    result3.correctAnswers = 18;

    results.push_back(result1);
    results.push_back(result2);
    results.push_back(result3);

    // Подсчет и вывод информации о неудовлетворительных результатах за прошлый год
    int unsatisfactoryResults = 0;

    for (const auto& res : results) {
        int startHours, startMinutes, startSeconds;
        int endHours, endMinutes, endSeconds;

        char colon;

        // Преобразование времени начала и окончания теста в секунды
        std::istringstream ss_start(res.startTime);
        ss_start >> startHours >> colon >> startMinutes >> colon >> startSeconds;

        std::istringstream ss_end(res.endTime);
        ss_end >> endHours >> colon >> endMinutes >> colon >> endSeconds;

        int startTimeInSeconds = startHours * 3600 + startMinutes * 60 + startSeconds;
        int endTimeInSeconds = endHours * 3600 + endMinutes * 60 + endSeconds;

        int timeDifference = endTimeInSeconds - startTimeInSeconds;

        // Проверка на неудовлетворительный результат и его вывод
        if (res.correctAnswers < 18) {
            unsatisfactoryResults++;
            std::cout << "Неудовлетворительный результат " << res.examDate << ": " << res.fullName << std::endl;
        }
    }

    std::cout << "Всего неудовлетворительных результатов за прошлый год: " << unsatisfactoryResults << std::endl;

    // Ввод даты и поиск информации о положительном результате с минимальным временем
    std::string inputDate;
    std::cout << "Введите дату (ДДММГГГГ): ";
    std::cin >> inputDate;

    int minTime = 10000000000000000;
    std::string minTimeFullName;

    for (const auto& res : results) {
        if (res.examDate == inputDate && res.correctAnswers >= 18) {
            // Преобразование времени начала и окончания теста в секунды
            int startHours, startMinutes, startSeconds;
            int endHours, endMinutes, endSeconds;

            char colon;

            std::istringstream ss_start(res.startTime);
            ss_start >> startHours >> colon >> startMinutes >> colon >> startSeconds;

            std::istringstream ss_end(res.endTime);
            ss_end >> endHours >> colon >> endMinutes >> colon >> endSeconds;

            int startTimeInSeconds = startHours * 3600 + startMinutes * 60 + startSeconds;
            int endTimeInSeconds = endHours * 3600 + endMinutes * 60 + endSeconds;

            int timeDifference = endTimeInSeconds - startTimeInSeconds;

            // Поиск минимального времени
            if (timeDifference < minTime) {
                minTime = timeDifference;
                minTimeFullName = res.fullName;
            }
        }
    }

    // Вывод информации о положительном результате с минимальным временем
    if (minTime != 1000000000000000) {
        std::cout << "Положительный результат на " << inputDate << " с минимальным временем: " << minTimeFullName << std::endl;
    } else {
        std::cout << "Информация о положительном результате для введенной даты отсутствует или дата введена некорректно." << std::endl;
    }

    // Сортировка результатов по дате и создание файлов
    std::sort(results.begin(), results.end(), compareDates);

    for (const auto& res : results) {
        if (res.correctAnswers < 18) {
            // Создание файла для неудовлетворительных результатов по каждой дате
            std::ofstream outFile("/Users/elinagalimova/Downloads/proga-3-semestr-C-/Cpp_Romanenko" + res.examDate + ".txt", std::ios::app);

            outFile << "Неудовлетворительный результат " << res.examDate << ": " << res.fullName << std::endl;
            outFile.close();
        }
    }

    return 0;
}
