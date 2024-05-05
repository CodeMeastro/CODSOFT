#include "SimpleCalculator.h"
#include<iostream>
#include<string>
using namespace std;

//Functions Prototypes
int choiceValidation(int a, int b, int c);
double integerValidation(double a);

int main() {

	//Declarations
	double digit1 = 0, digit2 = 0; int choice = 0;

	//User's Input
	cout << "Enter Integers!!" << endl;
	cout << "Integer 1 : "; cin >> digit1;
	cout << "Integer 2 : "; cin >> digit2;

	//Loop
	do {
		cout << endl;

		//Choices
		cout << "Enter Your Choice" << endl;
		cout << "-----------------" << endl;
		cout << "1. Addition" << endl;
		cout << "2. Subtraction" << endl;
		cout << "3. Multiplication" << endl;
		cout << "4. Division" << endl;
		cout << "5. Modulus" << endl;
		cout << "6. Exit" << endl;
		cout << "-----------------" << endl;
		cin >> choice;

		//Validation Of Input
		choice = choiceValidation(choice, 0, 6);
		cout << endl;

		//Instance of Calculator class Created For Calculations
		Calculator calculate(digit1, digit2);

		if (choice == 1)
			cout << "After Addition : " << calculate.performAddition() << endl;

		else if (choice == 2)
			cout << "After Subtraction : " << calculate.performSubtraction() << endl;

		else if (choice == 3)
			cout << "After Multiplication : " << calculate.performMultiplication() << endl;

		else if (choice == 4)
			cout << "After Division : " << calculate.performDivision() << endl;

		else if (choice == 5)
			cout << "After Mod : " << calculate.performModulus() << endl;

		else if (choice == 6)
			cout << "Thanks For using!!" << endl;

	} while (choice != 6);

	return 0;
}

int choiceValidation(int a, int b, int c) {
	bool check = true;

	do {
		check = true;
		if (a<b || a>c) {
			cout << "Invalid Choice Entered!!" << endl;
			cout << "Enter again : "; cin >> a;
			check = false;
		}
	} while (!check);

	return a;
}

double integerValidation(double a) {
	bool check = true;

	do {
		check = true;
		if (isalpha(a)) {
			cout << "Enter Again : "; cin >> a;
			check = false;
		}
	} while (!check);

	return a;
}