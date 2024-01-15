#pragma once
#include "Share_Fn.h"

class Car
{
private:
	int passWord[8] = { 0 };
	int safetyDistanc[3] = { 0 };
public:
	int* getPassword();
	int* getSafetyDistance();

	void setPassword(int newPassWord[8]);
	void setSafetyDistance(int newSafetyDistanc[3]);

	void displayInfo();
};

