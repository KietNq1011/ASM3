#include "MH2.h"

void resetSD(int* org_arr, int size)
{
	string choice;
	do {
		system("cls");
		cout << "Your safety distance is: ";
		printArr(org_arr, size);
		cout << "\nDo you want to reset your SD? (Y/N): ";
		getline(cin, choice);

		if (choice != "Y" && choice != "y" && choice != "N" && choice != "n") {
			cout << "PLEASE ENTER 'Y' or 'N'!" << endl;
			system("pause");
		}
		else if (choice == "Y" || choice == "y") {
			system("cls");
			cout << "Let's set your SD\n";
			write_data_toFile(org_arr, size, SD_PATH);
			cout << "SD reset successfully!" << endl;
		}
	} while (choice != "Y" && choice != "N" && choice != "y" && choice != "n");

	system("pause");
	system("cls");
}

void updateSD(int* arr, const int size, const string File_PATH) 
{
	fstream FileIn(File_PATH, ios::in);

	if (!FileIn.is_open()) {
		cout << "Failed to open file." << endl;
		return;
	}

	string data_name = "SAFETY DISTANCE";

	// Read the whole file into a string
	string fileContent((istreambuf_iterator<char>(FileIn)), istreambuf_iterator<char>());
	// Find the position of MSCN or SD in the file
	size_t dataPos = fileContent.find(data_name + ":");
	// Find the end of the line
	size_t endOfLinePos = fileContent.find("\n", dataPos);
	if (endOfLinePos == string::npos) {
		endOfLinePos = fileContent.length();
	}

	// Get the new data string
	string newData = data_name + ": ";
	for (int i = 0; i < size; i++) {
		newData += to_string(arr[i]) + " ";
	}

	// Replace the old MSCN string with the new one
	fileContent.replace(dataPos, endOfLinePos - dataPos, newData);

	// Write the new content to the file
	ofstream FileOut(File_PATH, ios::out);
	FileOut << fileContent;

	FileIn.close();
	FileOut.close();
}

void display_MH2(int* org_SD, int* SD_sorted, const int size, bool FirstUse)
{
	readDataFromFile(org_SD, SD_sorted, size, SD_PATH, FirstUse);
	if (!FirstUse) {
		if (!compare_2Arr(SD_sorted, org_SD, 3)) {
			cout << "\nTHE SAFETY DISTANCE YOU JUST ENTERED IS DIFFERENT FROM THE ONE STORED IN THE VEHICLE.";
			cout << "\nNOW I WILL PROCEED TO UPDATE IT. \nUPDATING...";
			updateSD(SD_sorted, size, SD_PATH);
			cout << "\nUPDATED YOUR SD!" << endl;
			system("pause");
		}
	}
	else {
		resetSD(org_SD, size);
	}
}