#pragma once
#include "Share_Fn.h"

// Function to display the speed menu
void displaySpeedMenu(int& gear, int& speed);

// Function for displaying safe distance based on speed
void safeDistance(int* SD_sorted, int& v);

// Function for showing MH4 options
int showOptionMH4(int& speed, int* SD_sorted, int choice, int& gear);

// Function for checking speed and displaying warnings
void checkSpeed(int choice, int& speed, int* SD_sorted, int& gear);