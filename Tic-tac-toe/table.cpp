#include <iostream>
#include <cstdlib>
#include <ctime>
#include "table.h"

// previous
// void Table::playerSetValue(int x, int y) {
// 	this->table[x][y] = Elem::O;
// 	return;
// }

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
    int random_number;

    srand(time(NULL));
    
    // 行動1回目-奇数(1, 3, 5, 7, 9)
    if (count == 1) {
        std::cout << "↓ コンピュータの行動 ↓" << std::endl;
        random_number = rand() % 9 + 1;
        if (random_number % 2 == 0) {
            random_number += 1;
        }
        this->cpuPos(random_number);
    }
    // 行動2回目
    else if (count == 2) {
        std::cout << "↓ コンピュータの行動 ↓" << std::endl;

        // Xが1, 3, 7, 9にある時
        if (this->checkTable(1) == 3 || this->checkTable(3) == 3 || this->checkTable(7) == 3 || this->checkTable(9) == 3) {
            if (this->checkTable(5) == 1) {
                if (this->checkTable(1) == 3 && this->checkTable(9) != 2) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(5);
                    }
                    else {
                        this->cpuPos(9);
                    }
                }
                else if (this->checkTable(3) == 3 && this->checkTable(7) != 2) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(5);
                    }
                    else {
                        this->cpuPos(7);
                    }
                }
                else if (this->checkTable(7) == 3 && this->checkTable(3) != 2) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(3);
                    }
                    else {
                        this->cpuPos(5);
                    }
                }
                else if (this->checkTable(9) == 3 && this->checkTable(1) != 2) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(1);
                    }
                    else {
                        this->cpuPos(5);
                    }
                }
                else if ((this->checkTable(1) == 3 && this->checkTable(9) == 2) || (this->checkTable(9) == 3 && this->checkTable(1) == 2)) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(3);
                    }
                    else {
                        this->cpuPos(7);
                    }
                }
                else if ((this->checkTable(3) == 3 && this->checkTable(7) == 2) || (this->checkTable(7) == 3 && this->checkTable(3) == 2)) {
                    random_number = rand() % 2;
                    if (random_number == 0) {
                        this->cpuPos(1);
                    }
                    else {
                        this->cpuPos(9);
                    }
                }
            }
            // 3か7
            else if (this->checkTable(1) == 3 || this->checkTable(9) == 3) {
                random_number = rand() % 2;

                if (random_number == 0) {
                    this->cpuPos(3);
                }
                else {
                    this->cpuPos(7);
                }
            }
            // 1か9
            else if (this->checkTable(3) == 3 || this->checkTable(7) == 3) {
                random_number = rand() % 2;

                if (random_number == 0) {
                    this->cpuPos(1);
                }
                else {
                    this->cpuPos(9);
                }
            }
        }
        // Xが5にある時
        else {
            if (this->checkTable(1) == 2 || this->checkTable(9) == 2) {
                random_number = rand() % 2;

                if (random_number == 0) {
                    this->cpuPos(3);
                }
                else {
                    this->cpuPos(7);
                }
            }
            else if (this->checkTable(3) == 2 || this->checkTable(7) == 2) {
                random_number = rand() % 2;

                if (random_number == 0) {
                    this->cpuPos(1);
                }
                else {
                    this->cpuPos(9);
                }
            }
            else {
                random_number = rand() % 9 + 1;
                if (random_number % 2 == 0) {
                    random_number += 1;
                }
                this->checkTable(random_number);
            }
        }
    }
    // 行動3回目
    else if (count == 3) {
        std::cout << "↓ コンピュータの行動 ↓" << std::endl;
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