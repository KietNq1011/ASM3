#pragma once
#include "Share_Fn.h"

// so sánh với MSCN trong file
bool checkPassword(int* org_arr, int* arr, const int size);

// Reset password
void resetPassword(int* org_arr, int size);

// Display MH1
bool display_MH1(int* org_arr, int* arr, const int size, bool FirstUse);