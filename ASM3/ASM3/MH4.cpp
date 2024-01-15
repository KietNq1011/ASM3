#include "MH4.h"

// Function to display the speed menu
void displaySpeedMenu(int& gear, int& speed) {
	if ((gear == 4 && speed >= 60) || (gear == 2 && speed >= 20)) {
		cout << "CANH BAO: Toc do qua cao cho lai xe!" << endl;
	}

	cout << "TOC DO HIEN TAI: " << speed << "km/h" << endl;
	cout << "MOI LUA CHON" << endl;
	cout << "1. TANG TOC" << endl;
	cout << "2. GIAM TOC" << endl;
	cout << "3. PHANH" << endl;
	cout << "4. TRO VE MENU" << endl;
}

// Function for displaying safe distance based on speed
void safeDistance(int* SD_sorted, int& v) {
	if (v <= SD_sorted[0]) {
		cout << "BAN GIU KHOANG CACH TOI THIEU LA 20m" << endl;
	}
	else if (v > SD_sorted[0] && v <= SD_sorted[1]) {
		cout << "BAN GIU KHOANG CACH TOI THIEU LA 55m" << endl;
	}
	else if (v > SD_sorted[1] && v <= SD_sorted[2]) {
		cout << "BAN GIU KHOANG CACH TOI THIEU LA 70m" << endl;
	}
	else {
		cout << "BAN GIU KHOANG CACH TOI THIEU LA 100m" << endl;
	}
}

// Function for showing MH4 options
int showOptionMH4(int& speed, int* SD_sorted, int choice, int& gear) {
	int action;
	string temp;

	do {
		safeDistance(SD_sorted, speed);
		displaySpeedMenu(gear, speed);

		cout << "Choice: ";
		getline(cin, temp);

		if (temp.empty() || !isNumber(temp) || temp.size() > 1 || stoi(temp) < 1 || stoi(temp) > 4) {
			cout << "Lua chon khong hop le! Vui long nhap lai!" << endl;
			system("pause");
			system("cls");
		}
		else {
			action = stoi(temp);
			break;
		}
	} while (true);

	return action;
}

// Function for checking speed and displaying warnings
void checkSpeed(int choice, int& speed, int* SD_sorted, int& gear)
{
	if ((speed > 0) && (gear == 4 || gear == 2)) {
		while (true) {
			int action = showOptionMH4(speed, SD_sorted, choice, gear);

			if (action == 1) {
				speed += 5;
				system("cls");
			}
			else if (action == 2) {
				speed -= 5;
				if (speed <= 0) {
					speed = 0;
				}
				system("cls");
			}
			else if (action == 3) {
				system("cls");
				speed = 0;
			}
			else {
				system("cls");
				break;
			}
		}
	}
}
