#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <limits>
#include <algorithm>

using namespace std;

const string MSCN_PATH = "MSCN.dat";

const string SD_PATH = "SD.dat";

extern int countSelection;
extern int countBubble;

// Sort Fns
void bubbleSort(int* arr, int arraySize, int& count);
void selectionSort(int* arr, int arraySize, int& count);
void compareSorts(int& countBubble, int& countSelection);

// Compare Fn
bool compare_2Arr(const int* org_arr, const int* inputted_arr, const int arr_size);

// Check input is number or not
bool isNumber(const string& str);

// Enter arr
void enterArr(int* arr, const int arr_size);

// Print arr
void printArr(int* arr, const int arr_size);

//Copy arr
void copyArray(int source[], int destination[], int size);

// Check if this is 1st time car has been used
bool isFirstUse();


// Read data from file
void readDataFromFile(int* org_arr, int* arr, const int size, const string File_PATH, bool FirstUse);

// Write data to a file
void write_data_toFile(int* arr, const int size, const string File_PATH);