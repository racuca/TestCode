#include <iostream>
#define MAX_SEAT 8
#define FULL_TIME 3
using namespace std;

class Console {
public:
	static int banner();
	static string time();
	int seatnumber();
	string inputname();
};

int Console::banner() {
	int banner = 0;

	cout << "����:1, ���:2, ����:3, ������:4>> ";
	cin >> banner;
	return banner;
}
string Console::time() {
	int time = 0;
	string h[FULL_TIME];

	cout << "07��:1, 12��:2, 17��:3>> ";
	cin >> time;
	if (time == 1) {
		h[0] == "07��";
	}
	if (time == 2) {
		h[1] == "12��";
	}
	if (time == 3) {
		h[2] == "17��";
	}
	return h[FULL_TIME];
}

int Console::seatnumber() {
	int number = 0;

	cout << "�¼� ��ȣ>> ";
	cin >> number;
	return number;
}

string Console::inputname() {
	string name;

	cout << "�̸� �Է�>> ";
	cin >> name;
	return name;
}
class Seat {
public:
	Seat();
	string shape() {
		return "---";
	}
};

Seat::Seat() {
	int banner = 0;
	Console* menu = NULL;
	Seat* seat[MAX_SEAT];
	string s[MAX_SEAT];
	string time[FULL_TIME];

	while (1) {
		banner = menu->banner();

		if (banner == 1) {
			for (int a = 0; a < FULL_TIME; a++) {
				time[a] = menu->time();
				cout << time[a] << ":";
				for (int i = 0; i < MAX_SEAT; i++) {
					seat[i] = new Seat();
					s[i] = seat[i]->shape();
					cout << "   " << s[i];
					cout << endl;
					menu->seatnumber();
					if (s[i] != "---") {
						s[i] = menu->inputname();
					}
				}
			}
			break;
		}
		if (banner == 2) {
			for (int a = 0; a < FULL_TIME; a++) {
				time[a] = menu->time();
				cout << time[a] << ":";
				for (int i = 0; i < MAX_SEAT; i++) {
					seat[i] = new Seat();
					s[i] = seat[i]->shape();
					cout << "   " << s[i];
					cout << endl;
					menu->seatnumber();
					menu->inputname();
					if (s[i] == menu->inputname()) {
						s[i] = seat[i]->shape();
					}
				}
			}
			break;
		}
		if (banner == 3) {
			for (int a = 0; a < FULL_TIME; a++) {
				time[a] = menu->time();
				for (int i = 0; i < MAX_SEAT; i++) {
					cout << "   " << s[i];
					cout << endl;
				}
			}
			break;
		}
		if (banner == 4) {
			cout << endl << "���� �ý����� �����մϴ�." << endl;
			exit(1);
		}
	}
}

class Schedule {
public:
	Schedule() {
		Schedule* schedule[FULL_TIME];
		for (int i = 0; i < FULL_TIME; i++) {
			schedule[i] = new Schedule();
			Seat();
		}
	}
};

class AirlineBook {
public:
	AirlineBook() {
		Schedule();
	}
};

int main() {
	cout << "***** �Ѽ��װ��� ���Ű��� ȯ���մϴ� *****" << endl << endl;
	AirlineBook* airlinebook;
	airlinebook = new AirlineBook();
	AirlineBook();
}