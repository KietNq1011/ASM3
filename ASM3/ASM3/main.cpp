#include "MH1.h"
#include "MH2.h"
#include "MH3.h"
#include "MH4.h"
#include "Share_Fn.h"
#include "Car.h"

#define Password_size 8
#define SD_size 3
#define P 1
#define R 2
#define N 3
#define D 4

// count variables declare in share fns with extern
int countSelection = 0;
int countBubble = 0;

int main()
{
	ifstream FileIn(MSCN_PATH, ios::in);


	if (!FileIn.is_open())
	{
		cout << "Failed to open file." << endl;
		FileIn.close();
		return 0;
	}

	bool FirstUse = isFirstUse();
	int speed = 0;
	int gear = 0;

	int org_SD[3] = { 0 };
	int SD_sorted[3] = { 0 };

	int org_arr[8] = { 0 };
	int arr[8] = { 0 };

	if (!display_MH1(org_arr, arr, Password_size, FirstUse))
	{
		cout << "Goodbye!" << endl;
		return 0;
	}

	// setting safety distance
	display_MH2(org_SD, SD_sorted, SD_size, FirstUse);

	Car newCar;
	newCar.setPassword(org_arr);
	newCar.setSafetyDistance(org_SD);
	newCar.displayInfo();
	system("pause");
	system("cls");


	while (true) {
		int choice = chooseOption(speed);

		// check if change gear but speed is 0km/h
		if (choice != gear && speed > 0) {
			cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0KM/H" << endl;
			system("pause");
			continue;
		}

		switch (choice) {
		case 1:
			system("cls");
			gear = P;
			gearP();
			system("pause");
			break;
		case 2:
			system("cls");
			gear = R;
			gearR(speed);
			break;
		case 3:
			system("cls");
			gear = N;
			gearN();
			system("pause");
			break;
		case 4:
			system("cls");
			gear = D;
			gearD(speed);
			break;
		case 5:
			system("cls");
			cout << "XE DA DUOC TAT. TAM BIET" << endl;
			return 0;
		default:
			system("cls");
			cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
			system("pause");
			continue;
		}

		checkSpeed(choice, speed, SD_sorted, gear);
	}

	return 0;
}
