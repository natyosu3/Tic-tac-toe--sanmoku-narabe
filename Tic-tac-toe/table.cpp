#include <iostream>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include "table.h"

using Reach = std::tuple<int, int>;

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


Reach Table::get_reach(int select) {
    if (select == 1) {
        // �c��2��
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (this->table[0][i] == Elem::O && this->table[1][i] == Elem::O && this->table[2][i] == Elem::Empty) {
                return { 2, i };
            }
            if (this->table[0][i] == Elem::O && this->table[1][i] == Elem::Empty && this->table[2][i] == Elem::O) {
                return { 1, i };
            }
            if (this->table[0][i] == Elem::Empty && this->table[1][i] == Elem::O && this->table[2][i] == Elem::O) {
                return { 0, i };
            }
        }
        // ����2��
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
        // �΂߂�2��
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
        // ����2��
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (this->table[0][i] == Elem::X && this->table[1][i] == Elem::X && this->table[2][i] == Elem::Empty) {
                return { 2, i };
            }
            if (this->table[0][i] == Elem::X && this->table[1][i] == Elem::Empty && this->table[2][i] == Elem::X) {
                return { 1, i };
            }
            if (this->table[0][i] == Elem::Empty && this->table[1][i] == Elem::X && this->table[2][i] == Elem::X) {
                return { 0, i };
            }
        }
        // �c��2��
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
        // �΂߂�2��
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

int Table::act_after_third() {
    std::cout << "�� �R���s���[�^�̍s�� ��" << std::endl;
    int j = 1;
    int i = 1;
    bool flag = false;

    for (i = 1; i < 10; i++) {
        if (this->checkTable(i) == 3) {
            Reach reach = this->get_reach(2);
            if (std::get<0>(reach) != -1) {
                this->cpuPos(swith_table(std::get<0>(reach), std::get<1>(reach)));
                return 1;
                break;
            }
            else {
                // ���胊�[�`������ꍇ                
                Reach reach = this->get_reach(1);
                if (std::get<0>(reach) != -1) {
                    this->cpuPos(swith_table(std::get<0>(reach), std::get<1>(reach)));
                    break;
                }
                else {
                    for (j = 1; j < 10; j++) {
                        if (this->checkTable(j) == 1) {
                            this->cpuPos(j);
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        return -1;
                        break;
                    }
                }
            }
        }
    }
}

void Table::cpuSetValue() {
    static int count = 1;
    int finc = 0;
    static int move_history1, move_history2;
    int random_number;
    srand(time(NULL));
    
    // �s��1���-�(1, 3, 5, 7, 9)
    if (count == 1) {
        std::cout << "�� �R���s���[�^�̍s�� ��" << std::endl;
        random_number = rand() % 9 + 1;
        if (random_number % 2 == 0) {
            random_number += 1;
        }
        this->cpuPos(random_number);
        move_history1 = random_number;
    }
    // �s��2���
    else if (count == 2) {
        std::cout << "�� �R���s���[�^�̍s�� ��" << std::endl;

        // X��1, 3, 7, 9�ɂ��鎞
        if (this->checkTable(1) == 3 || this->checkTable(3) == 3 || this->checkTable(7) == 3 || this->checkTable(9) == 3) {
            // 5����̏ꍇ
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
            // 3��7
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
            // 1��9
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
        // X��5�ɂ��鎞
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
    // �s��3���
    else if (count == 3) {
        finc = this->act_after_third();
    }
    // �s��4���
    else if (count == 4) {
        finc = this->act_after_third();
    }
    // �s��5���
    else if (count == 5) {
        this->act_after_third();
        count = 0;
    }
    if (finc == 1) {
        count = 0;
    }
    count++;
}


int Table::checkTable(int pos) {
    // �K���ɏ�����
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

int Table::winDecision() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (this->table[0][i] == Elem::O && this->table[1][i] == Elem::O && this->table[2][i] == Elem::O) {
            return 1;
        }
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (this->table[i][0] == Elem::O && this->table[i][1] == Elem::O && this->table[i][2] == Elem::O) {
            return 1;
        }
    }
    if (this->table[0][0] == Elem::O && this->table[1][1] == Elem::O && this->table[2][2] == Elem::O) {
        return 1;
    }
    if (this->table[0][2] == Elem::O && this->table[1][1] == Elem::O && this->table[2][0] == Elem::O) {
        return 1;
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (this->table[0][i] == Elem::X && this->table[1][i] == Elem::X && this->table[2][i] == Elem::X) {
            return 2;
        }
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (this->table[i][0] == Elem::X && this->table[i][1] == Elem::X && this->table[i][2] == Elem::X) {
            return 2;
        }
    }
    if (this->table[0][0] == Elem::X && this->table[1][1] == Elem::X && this->table[2][2] == Elem::X) {
        return 2;
    }
    if (this->table[0][2] == Elem::X && this->table[1][1] == Elem::X && this->table[2][0] == Elem::X) {
        return 2;
    }
    return -1;
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

// �Ֆʂ����Z�b�g
void Table::resetTable() {
    table = std::vector<std::vector<Elem>>(TABLE_SIZE, std::vector<Elem>(TABLE_SIZE, Elem::Empty));
}

// �R���X�g���N�^
Table::Table() {
	std::cout << "�R���X�g���N�^���Ăяo����܂����B" << std::endl;
	// table = std::vector<std::vector<Elem>>(TABLE_SIZE, std::vector<Elem>(TABLE_SIZE, Elem::Empty));
    resetTable();
}