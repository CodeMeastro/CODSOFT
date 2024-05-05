#pragma once

#include<iostream>
#include<iomanip>
using namespace std;

class Calculator {
	double firstInteger;
	double secondInteger;
	double integerValidation(double);
public:
	Calculator();
	Calculator(double first, double second);

	//Setters
	void setFirstInteger(double first);
	void setSecondInteger(double second);

	//getters
	double getFirstInteger()const;
	double getSecondInteger()const;

	//operations
	double performAddition() const;
	double performSubtraction()const;
	double performMultiplication()const;
	double performDivision() const;
	double performModulus()const;
};