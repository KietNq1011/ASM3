#include "Share_Fn.h"

// Sort Fns
void bubbleSort(int* arr, int arraySize, int& count) {
	// Reset count before starting the algorithm
	count = 0;
	for (int i = 0; i < arraySize - 1; i++) {
		for (int j = 0; j < arraySize - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				count++;
			}
		}
	}
}

void selectionSort(int* arr, int arraySize, int& count) {
	// Reset count before starting the algorithm
	count = 0;
	for (int i = 0; i < arraySize - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < arraySize; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
				count++;
			}
		}
		swap(arr[min_idx], arr[i]);
	}
}

void compareSorts(int& countBubble, int& countSelection)
{
	cout << "Numbers steps of the bubble sort algorithm: " << countBubble << endl;
	cout << "Numbers steps of the selection sort algorithm: " << countSelection << endl;
	if (countBubble < countSelection) {
		cout << "Bubble Sort is faster" << endl;
	}
	else if (countBubble > countSelection) {
		cout << "Selection Sort is faster" << endl;
	}
	else {
		cout << "Both algorithms have the same number of steps" << endl;
	}
}

// Compare Fn
bool compare_2Arr(const int* org_arr, const int* inputted_arr, const int arr_size) {
	// Compare two arrays
	for (int i = 0; i < arr_size; i++) {
		if (inputted_arr[i] != org_arr[i]) {
			return false;
		}
	}
	return true;
}

// Enter arr
void enterArr(int* arr, const int arr_size) 
{
	for (int i = 0; i < arr_size; i++) {
		string temp;
		bool isDuplicate;
		do {
			isDuplicate = false;
			cout << "\nENTER NUMBER " << i + 1 << ": ";
			getline(cin, temp);
			if (!isNumber(temp)) {
				cout << "PLEASE ENTER A NUMBER!" << endl;
			}
			else if (arr_size == 3) {
				for (int j = 0; j < i; j++) {
					if (stoi(temp) == arr[j]) {
						cout << "Vui long nhap so khac so da nhap vao!" << endl;
						isDuplicate = true;
						break;
					}
				}
			}
		} while (!isNumber(temp) || isDuplicate);
		arr[i] = stoi(temp);
	}

	if (arr_size == 3)
	{
		bubbleSort(arr, 3, countBubble);
	}
}

// Print arr
void printArr(int* arr, const int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Check input 
bool isNumber(const string& str)
{
	if (str.empty()) return false;

	for (char const& c : str) {
		if (isdigit(c) == 0) return false;
	}

	return true;
}

// Check if this is 1st time car has been used
bool isFirstUse()
{
	ifstream FileIn(MSCN_PATH, ios::in);

	// Get the file size
	FileIn.seekg(0, ios::end);  // moves the file pointer to the end of the file.
	streampos fileSize = FileIn.tellg(); // tellg: return pointer position. assign it to file size
	FileIn.seekg(0, ios::beg); // reset the file pointer to the beginning

	FileIn.close();

	if (fileSize == 0)
		return true;
	else
		return false;
}

// Read data from file
void readDataFromFile(int* org_arr, int* arr, const int size, const string File_PATH, bool FirstUse) {
	ifstream FileIn(File_PATH, ios::in);

	if (!FileIn.is_open())
	{
		cout << "Failed to open file." << endl;
		return;
	}

	string data_name = "";
	size == 3 ? data_name = "SAFETY DISTANCE" : data_name = "MSCN";

	// - nếu lần đầu thì yêu cầu cài đặt , sau đó ghi vào file
	if (FirstUse)
	{
		cout << "THIS IS THE FIRST TIME CAR HAS BEEN USED" << endl;
		cout << "PLEASE SET " << data_name << " !" << endl;

		ofstream outFile(File_PATH);
		enterArr(org_arr, size);
		copy(org_arr, org_arr + size, arr);

		outFile << data_name + ": ";
		for (int i = 0; i < size; i++) {
			outFile << org_arr[i] << " ";
		}

		outFile.close();
		cout << "SET" << data_name << " SUCCESSFULLY!\n";
		system("pause");
		system("cls");
	}
	// - nếu lần 2 trở đi thì lấy mảng cũ ra, sau đó nhập mảng để so sánh  
	else
	{
		string line;
		while (getline(FileIn, line)) {
			if (line.find(data_name + ":") != string::npos) {
				istringstream iss(line.substr(line.find(":") + 1));
				for (int i = 0; i < size; i++) {
					iss >> org_arr[i];
				}
				break;
			}
		}

		cout << "ENTER " << data_name << ", " << size << " - DIGIT ARRAY" << endl;
		enterArr(arr, size);

		system("pause");
		system("cls");
	}

	FileIn.close();
}

// Write data to a file
void write_data_toFile(int* arr, const int size, const string File_PATH)
{
	fstream FileIn(File_PATH, ios::in);

	if (!FileIn.is_open()) {
		cout << "Failed to open file." << endl;
		return;
	}

	string data_name = "";
	size == 3 ? data_name = "SAFETY DISTANCE" : data_name = "MSCN";

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
	cout << "ENTER " << data_name << ", " << size << " - DIGIT ARRAY" << endl;
	enterArr(arr, size);
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

// Copy arr
void copyArray(int source[], int destination[], int size) {
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
}