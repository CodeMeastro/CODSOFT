#include "SimpleCalculator.h"
#include<iostream>
#include<iomanip>
using namespace std;


Calculator::Calculator() {
	firstInteger = 0.0;
	secondInteger = 0.0;
}
Calculator::Calculator(double first, double second) {
	firstInteger = integerValidation(first);
	secondInteger = integerValidation(second);
}

//Setters
void Calculator::setFirstInteger(double first) {
	firstInteger = integerValidation(first);
}
void Calculator::setSecondInteger(double second) {
	secondInteger = integerValidation(second);
}

//getters
double Calculator::getFirstInteger()const {
	return firstInteger;
}
double Calculator::getSecondInteger()const {
	return secondInteger;
}

//operations
double Calculator::performAddition() const {
	return firstInteger + secondInteger;
}
double Calculator::performSubtraction() const {
	return firstInteger - secondInteger;
}
double Calculator::performMultiplication() const {
	return firstInteger * secondInteger;
}
double Calculator::performDivision() const {
	return static_cast<double>(max(firstInteger, secondInteger) / min(firstInteger + 0.0, secondInteger + 0.0));
}
double Calculator::performModulus()const {
	return int(firstInteger) % int(secondInteger);
}

double Calculator::integerValidation(double a) {
	bool check = true;

	do {
		check = true;
		if (a < 0.0 || isalpha(a)) {
			cout << "Enter Again  : ";
			cin >> a;
			check = false;
		}
	} while (!check);

	return a;
}