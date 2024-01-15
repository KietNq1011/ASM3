#include "MH1.h"


// so sánh với MSCN trong file
bool checkPassword(int* org_arr, int* arr, const int size)
{
	int arr2[8] = { 0 };
	copyArray(arr, arr2, size);

	cout << "MANG NHAP VAO TRUOC KHI SAP XEP: ";
	printArr(arr, size);
	bubbleSort(arr, size, countBubble);
	cout << "MANG NHAP VAO SAU KHI SAP XEP: ";
	printArr(arr, size);

	cout << "MA SO CA NHAN TRUOC KHI SAP XEP: ";
	printArr(org_arr, size);
	selectionSort(org_arr, size, countSelection);
	cout << "MA SO CA NHAN SAU KHI SAP XEP: ";
	printArr(org_arr, size);

	cout << endl << endl;

	// compare 2 algorithm
	selectionSort(arr2, size, countSelection);
	compareSorts(countBubble, countSelection);

	cout << endl << endl;

	if (compare_2Arr(org_arr, arr, size))
	{
		cout << "\nThe entered numbers is the same as the original." << endl;
		system("pause");
		system("cls");
		return 1;
	}
	else {
		cout << "\nThe entered numbers isn't the same as the original." << endl;
		cout << "\nBye Bye!!!";
		system("pause");
		return 0;
	}

}

// Reset password
void resetPassword(int* org_arr, int size)
{
	string choice;
	do {
		system("cls");
		cout << "Your password is: ";
		printArr(org_arr, 8);
		cout << "\nDo you want to reset your password? (Y/N): ";
		getline(cin, choice);

		if (choice != "Y" && choice != "y" && choice != "N" && choice != "n") {
			cout << "PLEASE ENTER 'Y' or 'N'!" << endl;
			system("pause");
		}
		else if (choice == "Y" || choice == "y") {
			system("cls");
			cout << "Let's set your password\n";
			write_data_toFile(org_arr, size, MSCN_PATH);
			cout << "Password reset successfully!" << endl;
		}
	} while (choice != "Y" && choice != "N" && choice != "y" && choice != "n");

	system("pause");
	system("cls");
}

// Display MH1
bool display_MH1(int* org_arr, int* arr, const int size, bool FirstUse)
{
	readDataFromFile(org_arr, arr, size, MSCN_PATH, FirstUse);
	if (!FirstUse) {
		if (!checkPassword(org_arr, arr, size))
			return 0;
		else {
			resetPassword(org_arr, size);
		}
	}
	return 1;
}