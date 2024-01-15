#include "MH3.h"


// Function to display the main menu
void displayMainMenu() {
	cout << "XIN MOI LUA CHON:" << endl;
	cout << "1. P" << endl;
	cout << "2. R" << endl;
	cout << "3. N" << endl;
	cout << "4. D" << endl;
	cout << "5. POWER OFF" << endl;
}

// Function for choosing gear option
int chooseOption(int& speed) {
	int choice = 0;
	string temp;

	do {
		system("cls");
		displayMainMenu();

		cout << "Choice: ";
		getline(cin, temp);

		if (temp.empty() || !isNumber(temp) || temp.size() > 1) {
			cout << "Lua chon khong hop le! Vui long nhap lai!" << endl;
			system("pause");
		}
		else {
			choice = stoi(temp);
		}
	} while (temp.empty() || !isNumber(temp) || temp.size() > 1);

	return choice;
}

// Function for gear P
void gearP() {
	system("cls");
	cout << "Da ve so P." << endl;
	cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN" << endl << endl;
}

// Function for gear N
void gearN() {
	system("cls");
	cout << "Da ve so N (Tam dung xe)." << endl;
}

// Function for gear R
void gearR(int& speed) {
	if (speed == 0) {
		system("cls");
		cout << "Da ve so R." << endl;
		speed = 7;
	}
}

// Function for gear D
void gearD(int& speed) {
	if (speed == 0) {
		system("cls");
		cout << "Da ve so D." << endl;
		speed = 7;
	}
}