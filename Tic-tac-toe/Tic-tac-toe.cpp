#include <iostream>
using namespace std;
#include "table.h"

void horizontal_line() {
	cout << "-----------------------------" << endl;
}

void resPlayer(Table *p) {
	int pos;

	while (true) {
		horizontal_line();
		cout << "○を打ちたい番号を指定して下さい: ";
		cin >> pos;
		if (cin.fail()) {
			cout << "please enter the valid number !" << endl;
		}
		else {
			horizontal_line();
			if (p->checkTable(pos) == -1) {
				cout << "既に埋まっています! 入力し直してください。" << endl;
			}
			else {
				p->playerSetValue(pos);
				break;
			}
		}
	}
}

int main()
{
	Table t;
	char cmd;
	int pos;

	cout << "------------------------\n三目並べ Tic-tac-toe\n------------------------" << endl;

	while (true) {
		cout << "開始するには\"s\"と入力して下さい!" << endl;
		cin >> cmd;
		if (cmd == 's') {
			system("cls");
			cout << "[OK] Let's enjoy it !!" << endl;
			break;
		}
		else {
			system("cls");
			cout << "[ERROR] plese enter valid command !" << endl;
		}
	}
	cout << "|1 2 3|\n|4 5 6|\tあなたがOを打ちたい位置の数字を入力して下さい。\n|7 8 9|" << endl;
	horizontal_line();

	t.printTable();

	resPlayer(&t);

	t.printTable();
	t.cpuSetValue();
	t.printTable();

	return 0;
}