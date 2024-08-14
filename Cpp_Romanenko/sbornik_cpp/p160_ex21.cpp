#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct ExamResult {
    std::string examDate;
    std::string fullName;
    std::string startTime;
    std::string endTime;
    int correctAnswers;
};

int main() {
    std::vector<ExamResult> results;

    // Ввод данных о сдаче экзамена
    ExamResult result;

    result.examDate = "01112021";
    result.fullName = "Петров Иван Петрович";
    result.startTime = "09:00:00";
    result.endTime = "09:30:00";
    result.correctAnswers = 19;

    results.push_back(result);

    
    std::cout << "Exam Results:" << std::endl;
    for (const auto& res : results) {
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

        std::cout << "Exam Date: " << res.examDate << std::endl;
        std::cout << "Full Name: " << res.fullName << std::endl;
        std::cout << "Correct Answers: " << res.correctAnswers << std::endl;
        std::cout << "Time Spent (seconds): " << timeDifference << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
