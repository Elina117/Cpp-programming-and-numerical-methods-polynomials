#include <iostream>
#include <cmath>

bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool ValidDay(int day, int month, int year)
{
    if(year>0 && month>=1 && month<=12 )
    {
        switch (month)
        {
            case 4:
            case 6:
            case 9:
            case 11:
                return (day>=1 && day<=30);
            case 2:
                if (isLeapYear(year))
                {
                    return (day >= 1 && day <= 29);
                }
                else 
                {
                    return (day >= 1 && day <= 28);
                }
            default:
                return (day >= 1 && day <= 31);
                
           

        }
    }

    return false;
}    

int main()
{
    int day;
    int month;
    int year;
    std:: cout << "Введите день, месяц и год: ";
    std:: cin >> day >> month >> year;

    if(ValidDay(day, month, year))
    {
        std::cout << "Дата корректна.";
    }
    else 
    {
        std::cout << "Дата не корректна.";
    }
}