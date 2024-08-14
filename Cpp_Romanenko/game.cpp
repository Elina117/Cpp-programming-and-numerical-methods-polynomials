#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

enum direction { v = 1, h = 2 }; //вертикальное и горизонтальное направление

class player {
public:
    bool defeat_flag;
    int hits[10][10]; // маска попаданий принимает либо 0 либо 1 или 9
    int ships[10][10]; // маска кораблей 1-море 2-корабль 3 убитый корабль

    player() {
        defeat_flag = 0;
        
    }

    void ships_init() {
        
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++) {
                hits[i][j] = 0;
                ships[i][j] = 1;
            }

        for (int i = 4; i > 0; i--)
            for (int j = i; j < 5; j++) {
                set(i);
                //Вызываем функцию, которая устанавливает корабли
            }
    }

    void set(int deck) {
        bool doit = true;
        direction d;

        do {
            if (rand() % 2)
                d = h;
            else
                d = v;

            int S = rand() % 10;
            int C = rand() % 10;
            doit = place_ship(S, C, d, deck);

        } while (!doit);
    }

    bool place_ship(int s, int c, direction dir, int desk) 
    {
        switch (dir) {
        case v:
            if (s >= desk - 1) {
                if (s == desk - 1) {
                    for (int i = 1; i >= -(desk - 1); i--)
                        for (int j = 1; j >= -1; j--) {
                            if (((s + i) < 0) || ((c + j) < 0))
                                continue;
                            if (((s + i) > 9) || ((c + j) > 9))
                                continue;

                            if (ships[s + i][c + j] == 2) {
                                return false;
                            }
                        }
                }
                if (s > desk - 1) {
                    for (int i = 1; i >= -desk; i--)
                        for (int j = 1; j >= -1; j--) {
                            if (((s + i) < 0) || ((c + j) < 0))
                                continue;
                            if (((s + i) > 9) || ((c + j) > 9))
                                continue;

                            if (ships[s + i][c + j] == 2) {
                                return false;
                            }
                        }
                }

                for (int i = desk; i > 0; i--)
                    ships[s - (desk - i)][c] = 2;
                return true;
            } else {
                return false;
            }
            break;
        case h:
            if (c >= desk - 1) {
                if (c == desk - 1) {
                    for (int i = 1; i >= -1; i--)
                        for (int j = 1; j >= -(desk - 1); j--) {
                            if (((s + i) < 0) || ((c + j) < 0))
                                continue;
                            if (((s + i) > 9) || ((c + j) > 9))
                                continue;

                            if (ships[s + i][c + j] == 2) {
                                return false;
                            }
                        }
                }
                if (c > desk - 1) {
                    for (int i = 1; i >= -1; i--)
                        for (int j = 1; j >= -desk; j--) {
                            if (((s + i) < 0) || ((c + j) < 0))
                                continue;
                            if (((s + i) > 9) || ((c + j) > 9))
                                continue;

                            if (ships[s + i][c + j] == 2) {
                                return false;
                            }
                        }
                }
                for (int i = desk - 1; i >= 0; i--)
                    ships[s][(c - i)] = 2;
                return true;
            } else {
                return false;
            }
            break;
        default:
            return false;
        }
    }

    bool turn(player& computer, int character, int digit) {
        if (computer.ships[digit][character] == 2) {
            computer.ships[digit][character] = 3;
            return true;
        }
        return false;
    }

    void turn(player&) {}
};

bool checkRange(int St, int _1, int _2, int End) {
    if ((St <= _1) && (St <= _2))
        if ((End >= _1) && (End >= _2))
            return true;
    return false;
}

const int s = 13, c = 29;
char map[s][c] = {
    "  0123456789     0123456789 ",
    " #----------#   #----------#",
    "0|          |  0|          |",
    "1|          |  1|          |",
    "2|          |  2|          |",
    "3|          |  3|          |",
    "4|          |  4|          |",
    "5|          |  5|          |",
    "6|          |  6|          |",
    "7|          |  7|          |",
    "8|          |  8|          |",
    "9|          |  9|          |",
    " #----------#   #----------#"};

player human;
player computer;

char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void map_init(char map[s][c]) {
    for (int i = 0; i < s; i++)
        for (int j = 0; j < c; j++) {
            if ((j >= 2) && (j <= 11))
                if ((i >= 2) && (i <= 11)) {
                    if (human.ships[i - 2][j - 2] == 1)
                        map[i][j] = 49;
                    if (human.ships[i - 2][j - 2] == 2)
                        map[i][j] = 50;
                    if (human.ships[i - 2][j - 2] == 3)
                        map[i][j] = 51;
                }
            if ((j >= 17) && (j <= 26))
                if ((i >= 2) && (i <= 11)) {
                    if (human.hits[i - 2][j - 17] == 0)
                        map[i][j] = 48;
                    if (human.hits[i - 2][j - 17] == 1)
                        map[i][j] = 49;
                    if (human.hits[i - 2][j - 17] == 9)
                        map[i][j] = 'A';
                }
        }
}

void show(char map[s][c]) {
    cout << endl;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < c; j++)
            cout << map[i][j];
        cout << endl;
    }
}

int input(char& character, char& digit) {
    int match = 0;
    cout << "\nEnter координату по строкам: ";
    cin >> character;
    cout << "\nEnter координату по столбцам: ";
    cin >> digit;

    for (int i = 0; i < 10; i++) {
        if (numbers[i] == character) {
            match += 1;
            character = i;
        }
        if (numbers[i] == digit) {
            match += 1;
            digit = i;
        }
    }
    return match;
}

void clearScreen() {
    system("clear"); 
}

void waitForInput() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int checkEnding() {
    if ((human.defeat_flag) || (computer.defeat_flag))
        return 2;
    else
        return 0;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int message = 0; // переменная хранит коды сообщений

    // установка начального значения генератора случайных чисел
    srand(time(NULL));

    human.ships_init();
    computer.ships_init();

    while (message != 2) {
        map_init(map);
        int user_input = 0;
        clearScreen();
        show(map);

        if (message == 1) // код сообщения 1 - введено неверное значение
            cout << "Вы ввели неверное значение!\n";

        message = 0;
        char character, digit;
        user_input = input(character, digit);

        if (user_input == 1) {
            message = 1;
            continue;
        }

        human.hits[character][digit] = 1;
        if (human.turn(computer, character, digit))
            human.hits[character][digit] = 9;
        computer.turn(human);

        message = checkEnding();
    }

    waitForInput();
    return 0;
}
