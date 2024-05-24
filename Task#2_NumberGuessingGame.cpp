#include<iostream>
#include<cmath>
using namespace std;

char againPlay();

char againPlay() {
	char again = 'y';
	do {
		cout << endl;
		cout << "Want to Play Again!!" << endl;
		cin >> again;
		again = tolower(again);
	} while (again != 'n' && again != 'y');

	return again;
}

int main() {

	//Declarations
	int number = 0, randomNumber = 0, attempts = 0;
	const int MaxValue = 100; const int MinValue = 0;
	bool check = false; char again = 'y';

	cout << "---------------------" << endl;
	cout << "We Have Generated a Random Number In the Range of 0-100" << endl;
	cout << "Guess What's that" << endl;
	cout << "---------------------" << endl;

	//Generating Numbers randomly with time
	srand(time(NULL));

	do {

		//Storing random number
		randomNumber = (rand() % (MaxValue - MinValue + 1)) + MinValue;

		//Running loop for 10 attempts only
		while (attempts < 10) {
			cout << "Enter Number : "; cin >> number;
			cout << endl;
			cout << "--------------" << endl;
			if (number < randomNumber)
				cout << "Too Less" << endl;

			else if (number > randomNumber)
				cout << "Too Large" << endl;

			else if (number == randomNumber) {
				cout << endl;
				cout << "You Got it, it was [" << number << "] !!" << endl;
				cout << "Total Attempts : 10" << endl;
				cout << "Your Attempts  : " << attempts << endl;
				if (attempts < 10)
					cout << "Congratulations! You Won" << endl;
				cout << "--------------" << endl;
				check = true;
				break;
			}
			attempts++;
			cout << "Attempts Left : " << 10 - attempts << endl;
			cout << "--------------" << endl;
			cout << endl;
		}

		if (!check) {
			cout << "Oops! You Lost All the Attempts" << endl;
			cout << "You Failed" << endl;
		}

		again = againPlay();

	} while (again == 'y');
	return 0;
}