#include "Car.h"

// Getter for password
int* Car::getPassword() {
	return passWord;
}

// Setter for password
void Car::setPassword(int newPassWord[8]) {
	for (int i = 0; i < 8; ++i) {
		passWord[i] = newPassWord[i];
	}
}

// Getter cho safetyDistanc
int* Car::getSafetyDistance() {
	return safetyDistanc;
}

// Setter cho safetyDistanc
void Car::setSafetyDistance(int newSafetyDistanc[3]) {
	for (int i = 0; i < 3; ++i) {
		safetyDistanc[i] = newSafetyDistanc[i];
	}
}

void Car::displayInfo() {
	cout << "Password: ";
	for (int i = 0; i < 8; ++i) {
		cout << passWord[i] << " ";
	}
	cout << endl;

	cout << "Safety Distance: ";
	for (int i = 0; i < 3; ++i) {
		cout << safetyDistanc[i] << " ";
	}
	cout << endl;
}