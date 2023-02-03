#include <iostream>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include "table.h"

using Reach = std::tuple<int, int>;


Reach Table::get_reach(int select) {
    if (select == 1) {
        // 横の2つ
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (this->table[0][i] == Elem::O && this->table[1][i] == Elem::O && this->table[2][i] == Elem::Empty) {
                return { 2, i };
            }
            if (this->table[0][i] == Elem::O && this->table[1][i] == Elem::Empty && this->table[2][i] == Elem::O) {
                return { 2, i };
            }
            if (this->table[0][i] == Elem::Empty && this->table[1][i] == Elem::O && this->table[2][i] == Elem::O) {
                return { 2, i };
            }
        }
        // 縦の2つ
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (this->table[i][0] == Elem::O && this->table[i][1] == Elem::O && this->table[i][2] == Elem::Empty) {
                return { i, 2 };
            }
            if (this->table[i][0] == Elem::O && this->table[i][1] == Elem::Empty && this->table[i][2] == Elem::O) {
                return { i, 1 };
            }
            if (this->table[i][0] == Elem::Empty && this->table[i][1] == Elem::O && this->table[i][2] == Elem::O) {
                return { i, 0 };
            }
        }
        // 斜めの2つ
        for (int i = 0; i < TABLE_SIZE - 1; i++) {
            if (this->table[0][0] == Elem::O && this->table[1][1] == Elem::O && this->table[2][2] == Elem::Empty) {
                return { 2, 2 };
            }
            if (this->table[0][0] == Elem::O && this->table[1][1] == Elem::Empty && this->table[2][2] == Elem::O) {
                return { 1, 1 };
            }
            if (this->table[0][0] == Elem::Empty && this->table[1][1] == Elem::O && this->table[2][2] == Elem::O) {
                return { 0, 0 };
            }
            if (this->table[0][2] == Elem::O && this->table[1][1] == Elem::O && this->table[2][0] == Elem::Empty) {
                return { 2, 0 };
            }
            if (this->table[0][2] == Elem::O && this->table[1][1] == Elem::Empty && this->table[2][0] == Elem::O) {
                return { 1, 1 };
            }
            if (this->table[0][2] == Elem::Empty && this->table[1][1] == Elem::O && this->table[2][0] == Elem::O) {
                return { 0, 2 };
            }
        }
        return { -1, -1 };
    }
    else {
        // 横の2つ
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (this->table[0][i] == Elem::X && this->table[1][i] == Elem::X && this->table[2][i] == Elem::Empty) {
                return { 2, i };
            }
            if (this->table[0][i] == Elem::X && this->table[1][i] == Elem::Empty && this->table[2][i] == Elem::X) {
                return { 2, i };
            }
            if (this->table[0][i] == Elem::Empty && this->table[1][i] == Elem::X && this->table[2][i] == Elem::X) {
                return { 2, i };
            }
        }
        // 縦の2つ
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (this->table[i][0] == Elem::X && this->table[i][1] == Elem::X && this->table[i][2] == Elem::Empty) {
                return { i, 2 };
            }
            if (this->table[i][0] == Elem::X && this->table[i][1] == Elem::Empty && this->table[i][2] == Elem::X) {
                return { i, 1 };
            }
            if (this->table[i][0] == Elem::Empty && this->table[i][1] == Elem::X && this->table[i][2] == Elem::X) {
                return { i, 0 };
            }
        }
        // 斜めの2つ
        for (int i = 0; i < TABLE_SIZE - 1; i++) {
            if (this->table[0][0] == Elem::X && this->table[1][1] == Elem::X && this->table[2][2] == Elem::Empty) {
                return { 2, 2 };
            }
            if (this->table[0][0] == Elem::X && this->table[1][1] == Elem::Empty && this->table[2][2] == Elem::X) {
                return { 1, 1 };
            }
            if (this->table[0][0] == Elem::Empty && this->table[1][1] == Elem::X && this->table[2][2] == Elem::X) {
                return { 0, 0 };
            }
            if (this->table[0][2] == Elem::X && this->table[1][1] == Elem::X && this->table[2][0] == Elem::Empty) {
                return { 2, 0 };
            }
            if (this->table[0][2] == Elem::X && this->table[1][1] == Elem::Empty && this->table[2][0] == Elem::X) {
                return { 1, 1 };
            }
            if (this->table[0][2] == Elem::Empty && this->table[1][1] == Elem::X && this->table[2][0] == Elem::X) {
                return { 0, 2 };
            }
        }
        return { -1, -1 };
    }

}


int swith_table(int x, int y) {
    if (x == 0 && y == 0) {
        return 1;
    }
    else if (x == 0 && y == 1) {
        return 2;
    }
    else if (x == 0 && y == 2) {
        return 3;
    }
    else if (x == 1 && y == 0) {
        return 4;
    }
    else if (x == 1 && y == 1) {
        return 5;
    }
    else if (x == 1 && y == 2) {
        return 6;
    }
    else if (x == 2 && y == 0) {
        return 7;
    }
    else if (x == 2 && y == 1) {
        return 8;
    }
    else if (x == 2 && y == 2) {
        return 9;
    }
}

bool Table::check_two_in_a_row() {
    // 横の2つ
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE - 1; j++) {
            if (this->table[i][j] == this->table[i][j + 1]) {
                return true;
            }
        }
    }
    // 縦の2つ
    for (int i = 0; i < TABLE_SIZE - 1; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            if (this->table[i][j] == this->table[i + 1][j]) {
                return true;
            }
        }
    }
    // 斜めの2つ
    for (int i = 0; i < TABLE_SIZE - 1; i++) {
        if (this->table[i][i] == this->table[i + 1][i + 1] ||
            this->table[i][TABLE_SIZE - i - 1] == this->table[i + 1][TABLE_SIZE - i - 2]) {
            return true;
        }
    }
    return false;
}

void Table::playerPos(int pos) {
    switch (pos) {
    case 1:
        this->table[0][0] = Elem::O;
        break;
    case 2:
        this->table[0][1] = Elem::O;
        break;
    case 3:
        this->table[0][2] = Elem::O;
        break;
    case 4:
        this->table[1][0] = Elem::O;
        break;
    case 5:
        this->table[1][1] = Elem::O;
        break;
    case 6:
        this->table[1][2] = Elem::O;
        break;
    case 7:
        this->table[2][0] = Elem::O;
        break;
    case 8:
        this->table[2][1] = Elem::O;
        break;
    case 9:
        this->table[2][2] = Elem::O;
        break;
    default:
        std::cout << "plese enter the valid data !" << std::endl;
        break;
    }
}

void Table::cpuPos(int pos) {
    switch (pos) {
    case 1:
        this->table[0][0] = Elem::X;
        break;
    case 2:
        this->table[0][1] = Elem::X;
        break;
    case 3:
        this->table[0][2] = Elem::X;
        break;
    case 4:
        this->table[1][0] = Elem::X;
        break;
    case 5:
        this->table[1][1] = Elem::X;
        break;
    case 6:
        this->table[1][2] = Elem::X;
        break;
    case 7:
        this->table[2][0] = Elem::X;
        break;
    case 8:
        this->table[2][1] = Elem::X;
        break;
    case 9:
        this->table[2][2] = Elem::X;
        break;
    default:
        std::cout << "[ERROR] inside of cpuPos" << std::endl;
        break;
    }
}

void Table::playerSetValue(int pos) {
    this->playerPos(pos);
}

void Table::cpuSetValue() {
    static int count = 1;
    static int move_history1, move_history2;
    int random_number;

    srand(time(NULL));
    
    // 行動1回目-奇数(1, 3, 5, 7, 9)
    if (count == 1) {
        std::cout << "↓ コンピュータの行動 ↓" << std::endl;
        // random_number = rand() % 9 + 1;
        random_number = 1;
        if (random_number % 2 == 0) {
            random_number += 1;
        }
        this->cpuPos(random_number);
        move_history1 = random_number;
    }
    // 行動2回目
    else if (count == 2) {
        std::cout << "↓ コンピュータの行動 ↓" << std::endl;

        // Xが1, 3, 7, 9にある時
        if (this->checkTable(1) == 3 || this->checkTable(3) == 3 || this->checkTable(7) == 3 || this->checkTable(9) == 3) {
            // 5が空の場合
            if (this->checkTable(5) == 1) {
                if (this->checkTable(1) == 3 && this->checkTable(9) != 2) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(5);
                        move_history2 = 5;
                    }
                    else {
                        this->cpuPos(9);
                        move_history2 = 9;
                    }
                }
                else if (this->checkTable(3) == 3 && this->checkTable(7) != 2) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(5);
                        move_history2 = 5;
                    }
                    else {
                        this->cpuPos(7);
                        move_history2 = 7;
                    }
                }
                else if (this->checkTable(7) == 3 && this->checkTable(3) != 2) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(3);
                        move_history2 = 3;
                    }
                    else {
                        this->cpuPos(5);
                        move_history2 = 5;
                    }
                }
                else if (this->checkTable(9) == 3 && this->checkTable(1) != 2) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(1);
                        move_history2 = 1;
                    }
                    else {
                        this->cpuPos(5);
                        move_history2 = 5;
                    }
                }
                else if ((this->checkTable(1) == 3 && this->checkTable(9) == 2) || (this->checkTable(9) == 3 && this->checkTable(1) == 2)) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(3);
                        move_history2 = 3;
                    }
                    else {
                        this->cpuPos(7);
                        move_history2 = 7;
                    }
                }
                else if ((this->checkTable(3) == 3 && this->checkTable(7) == 2) || (this->checkTable(7) == 3 && this->checkTable(3) == 2)) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(1);
                        move_history2 = 1;
                    }
                    else {
                        this->cpuPos(9);
                        move_history2 = 9;
                    }
                }
            }
            // 3か7
            else if (this->checkTable(1) == 3 || this->checkTable(9) == 3) {
                random_number = rand() % 2;

                if (random_number == 0) {
                    this->cpuPos(3);
                    move_history2 = 3;
                }
                else {
                    this->cpuPos(7);
                    move_history2 = 7;
                }
            }
            // 1か9
            else if (this->checkTable(3) == 3 || this->checkTable(7) == 3) {
                random_number = rand() % 2;

                if (random_number == 0) {
                    this->cpuPos(1);
                    move_history2 = 1;
                }
                else {
                    this->cpuPos(9);
                    move_history2 = 9;
                }
            }
        }
        // Xが5にある時
        else {
            if (this->checkTable(1) == 2 || this->checkTable(9) == 2) {
                random_number = rand() % 2;

                if (random_number == 0) {
                    this->cpuPos(3);
                    move_history2 = 3;
                }
                else {
                    this->cpuPos(7);
                    move_history2 = 7;
                }
            }
            else if (this->checkTable(3) == 2 || this->checkTable(7) == 2) {
                random_number = rand() % 2;

                if (random_number == 0) {
                    this->cpuPos(1);
                    move_history2 = 1;
                }
                else {
                    this->cpuPos(9);
                    move_history2 = 9;
                }
            }
            else {
                random_number = rand() % 9 + 1;
                if (random_number % 2 == 0) {
                    random_number += 1;
                }
                this->cpuPos(random_number);
                move_history2 = random_number;
            }
        }
    }
    // 行動3回目
    else if (count == 3) {
        std::cout << "↓ コンピュータの行動 ↓" << std::endl;

        if (this->checkTable(1) == 3) {
            if (this->checkTable(2) == 3 && this->checkTable(3) == 1) {
                this->cpuPos(3);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(3) == 3 && this->checkTable(2) == 1) {
                this->cpuPos(2);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(4) == 3 && this->checkTable(7) == 1) {
                this->cpuPos(7);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(5) == 3 && this->checkTable(9) == 1) {
                this->cpuPos(9);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(7) == 3 && this->checkTable(4) == 1) {
                this->cpuPos(4);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(9) == 3 && this->checkTable(5) == 1) {
                this->cpuPos(5);
                std::cout << "CPU WIN !!" << std::endl;
            }
            // 最善手以外    未完成
            else {
                // 相手リーチがある場合
                
                Reach reach = this->get_reach(1);
                if (std::get<0>(reach) == -1) {
                    for (int i = 1; i < 10; i++) {
                        if (this->checkTable(i) == 1) {
                            this->cpuPos(i);
                            break;
                        }
                    }
                }
                else {
                    std::cout << std::get<0>(reach) << "," << std::get<1>(reach) << std::endl;
                    std::cout << swith_table(std::get<0>(reach), std::get<1>(reach)) << std::endl;
                    this->cpuPos(swith_table(std::get<0>(reach), std::get<1>(reach)));
                }
            }
        }
        else if (this->checkTable(2) == 3) {
            if (this->checkTable(1) == 3 && this->checkTable(3) == 1) {
                this->cpuPos(3);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(3) == 3 && this->checkTable(1) == 1) {
                this->cpuPos(1);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(5) == 3 && this->checkTable(8) == 1) {
                this->cpuPos(8);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(8) == 3 && this->checkTable(5) == 1) {
                this->cpuPos(5);
                std::cout << "CPU WIN !!" << std::endl;
            }
        }
        else if (this->checkTable(3) == 3) {
            if (this->checkTable(2) == 3 && this->checkTable(1) == 1) {
                this->cpuPos(1);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(1) == 3 && this->checkTable(2) == 1) {
                this->cpuPos(2);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(4) == 3 && this->checkTable(9) == 1) {
                this->cpuPos(9);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(5) == 3 && this->checkTable(7) == 1) {
                this->cpuPos(7);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(7) == 3 && this->checkTable(5) == 1) {
                this->cpuPos(5);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(9) == 3 && this->checkTable(6) == 1) {
                this->cpuPos(6);
                std::cout << "CPU WIN !!" << std::endl;
            }
        }
        else if (this->checkTable(4) == 3) {
            if (this->checkTable(1) == 3 && this->checkTable(7) == 1) {
                this->cpuPos(7);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(5) == 3 && this->checkTable(6) == 1) {
                this->cpuPos(6);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(6) == 3 && this->checkTable(5) == 1) {
                this->cpuPos(5);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(7) == 3 && this->checkTable(1) == 1) {
                this->cpuPos(1);
                std::cout << "CPU WIN !!" << std::endl;
            }
        }
        else if (this->checkTable(5) == 3) {
            if (this->checkTable(1) == 3 && this->checkTable(9) == 1) {
                this->cpuPos(9);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(2) == 3 && this->checkTable(8) == 1) {
                this->cpuPos(8);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(3) == 3 && this->checkTable(7) == 1) {
                this->cpuPos(7);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(4) == 3 && this->checkTable(6) == 1) {
                this->cpuPos(6);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(6) == 3 && this->checkTable(4) == 1) {
                this->cpuPos(4);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(7) == 3 && this->checkTable(3) == 1) {
                this->cpuPos(3);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(8) == 3 && this->checkTable(2) == 1) {
                this->cpuPos(2);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(9) == 3 && this->checkTable(1) == 1) {
                this->cpuPos(1);
                std::cout << "CPU WIN !!" << std::endl;
            }
        }
        else if (this->checkTable(6) == 3) {
            if (this->checkTable(3) == 3 && this->checkTable(9) == 1) {
                this->cpuPos(9);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(4) == 3 && this->checkTable(5) == 1) {
                this->cpuPos(5);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(5) == 3 && this->checkTable(4) == 1) {
                this->cpuPos(4);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(9) == 3 && this->checkTable(3) == 1) {
                this->cpuPos(3);
                std::cout << "CPU WIN !!" << std::endl;
            }
        }
        else if (this->checkTable(7) == 3) {
            if (this->checkTable(1) == 3 && this->checkTable(4) == 1) {
                this->cpuPos(4);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(3) == 3 && this->checkTable(5) == 1) {
                this->cpuPos(5);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(4) == 3 && this->checkTable(1) == 1) {
                this->cpuPos(1);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(5) == 3 && this->checkTable(3) == 1) {
                this->cpuPos(3);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(8) == 3 && this->checkTable(9) == 1) {
                this->cpuPos(9);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(9) == 3 && this->checkTable(8) == 1) {
                this->cpuPos(8);
                std::cout << "CPU WIN !!" << std::endl;
            }
        }
        else if (this->checkTable(8) == 3) {
            if (this->checkTable(2) == 3 && this->checkTable(5) == 1) {
                this->cpuPos(5);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(5) == 3 && this->checkTable(2) == 1) {
                this->cpuPos(2);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(7) == 3 && this->checkTable(9) == 1) {
                this->cpuPos(9);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(9) == 3 && this->checkTable(7) == 1) {
                this->cpuPos(7);
                std::cout << "CPU WIN !!" << std::endl;
            }
        }
        else if (this->checkTable(9) == 3) {
            if (this->checkTable(1) == 3 && this->checkTable(5) == 1) {
                this->cpuPos(5);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(3) == 3 && this->checkTable(6) == 1) {
                this->cpuPos(6);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(5) == 3 && this->checkTable(1) == 1) {
                this->cpuPos(1);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(6) == 3 && this->checkTable(3) == 1) {
                this->cpuPos(3);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(7) == 3 && this->checkTable(8) == 1) {
                this->cpuPos(8);
                std::cout << "CPU WIN !!" << std::endl;
            }
            else if (this->checkTable(8) == 3 && this->checkTable(7) == 1) {
                this->cpuPos(7);
                std::cout << "CPU WIN !!" << std::endl;
            }
        }
    }
    count++;
}


int Table::checkTable(int pos) {
    // 適当に初期化
    Elem condition = Elem::X;

    switch (pos) {
    case 1:
        condition = this->table[0][0];
        break;
    case 2:
        condition = this->table[0][1];
        break;
    case 3:
        condition = this->table[0][2];
        break;
    case 4:
        condition = this->table[1][0];
        break;
    case 5:
        condition = this->table[1][1];
        break;
    case 6:
        condition = this->table[1][2];
        break;
    case 7:
        condition = this->table[2][0];
        break;
    case 8:
        condition = this->table[2][1];
        break;
    case 9:
        condition = this->table[2][2];
        break;
    default:
        std::cout << "[ERROR] inside of checkTable" << std::endl;
        break;
    }

    if (condition == Elem::Empty) {
        return 1;
    }
    else if (condition == Elem::O) {
        return 2;
    }
    else if (condition == Elem::X) {
        return 3;
    }
    else {
        return -1;
    }
}

void Table::printTable() {
    std::cout << "-----------------------------" << std::endl;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (int j = 0; j < TABLE_SIZE; ++j) {
            switch (table[i][j]) {
            case Elem::Empty:
                std::cout << '.' << ' ';
                break;
            case Elem::X:
                std::cout << 'X' << ' ';
                break;
            case Elem::O:
                std::cout << 'O' << ' ';
                break;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
}

// 盤面をリセット
void Table::resetTable() {
    table = std::vector<std::vector<Elem>>(TABLE_SIZE, std::vector<Elem>(TABLE_SIZE, Elem::Empty));
}

// コンストラクタ
Table::Table() {
	std::cout << "コンストラクタが呼び出されました。" << std::endl;
	// table = std::vector<std::vector<Elem>>(TABLE_SIZE, std::vector<Elem>(TABLE_SIZE, Elem::Empty));
    resetTable();
}