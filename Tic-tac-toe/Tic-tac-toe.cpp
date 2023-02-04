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
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			horizontal_line();
			if (p->checkTable(pos) != 1) {
				cout << "既に埋まっています! 入力し直してください。" << endl;
			}
			else {
				p->playerSetValue(pos);
				break;
			}
		}
	}
}

bool endDecision(Table* p) {
	if (p->winDecision() == 1) {
		p->printTable();
		cout << "You Are Winner !!" << endl;
		return true;
	}
	else if (p->winDecision() == 2) {
		p->printTable();
		cout << "You Are Loser -GG-" << endl;
		return true;
	}
	return false;
}

int main()
{
	while (true)
	{
		Table t;
		char cmd;
		int cnt = 0;
		bool fin = false;

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

		cout << "↓ 初期状態 ↓" << endl;
		while (true) {
			cnt += 1;
			t.printTable();
			t.cpuSetValue();
			if (endDecision(&t)) {
				break;
			}
			t.printTable();
			if (cnt == 5) {
				cout << "You Are Draw !" << endl;
				break;
			}
			resPlayer(&t);
			if (endDecision(&t)) {
				break;
			}
		}

		while (true) {
			cout << "もう一度対戦しますか? (y/n)" << endl;
			cin >> cmd;
			if (cmd == 'y') {
				system("cls");
				cout << "[OK] Let's enjoy it !!" << endl;
				break;
			}
			else if (cmd == 'n') {
				system("cls");
				fin = true;
				// delete &t;
				cout << "[OK] Thank You For Playing !!" << endl;
				break;
			}
			else {
				system("cls");
				cout << "[ERROR] plese enter valid command !" << endl;
			}
		}
		if (fin) {
			break;
		}
	}
	return 0;
}