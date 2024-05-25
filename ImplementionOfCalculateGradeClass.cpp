#include<iostream>
#include<string>
#include "CalculateGrade.h"
#include<iomanip>
using namespace std;

int validateNumbers();

int main() {
	string name; int total = 0; double marks = 0.0; char again = 'n';

	do {
		cout << "------------------------" << endl;
		cout << "Your Full Name : "; cin >> name;
		cout << "Total Subjects : "; cin >> total;
		if(isalpha(total))
		  total = validateNumbers();
		cout << "------------------------" << endl;

		CalculateGrade grading(name, total);

		for (int i = 0; i < total; i++) {
			cout << "Subject " << i + 1 << ":   "; cin >> marks;
			grading.setMarks(marks, i);
		}

		grading.setGrades();

		cout << endl;
		cout << "Now We Are Displaying Marks With Grades!!" << endl;
		cout << "--------------------------------" << endl;
		cout << "Subject No." << right << setw(10) << "Marks" << right << setw(10) << "Grade" << endl;
		cout << "--------------------------------" << endl;
		for (int i = 0; i < total; i++) {
			cout << right << setw(6) << i + 1 << right << setw(13) << grading.getMarks(i) << right << setw(10) << grading.getGrades(i) << endl;
		}
		cout << "--------------------------------" << endl;

		cout << endl; cout << endl;
		cout << "Hello! " << grading.getStudentName() << " Your " << endl;
		cout << "---------" << endl;
		cout << "Average Grade  :  " << grading.getAveragedGrade() << endl;
		cout << "Highest Grade  :  " << grading.getHighestGrade() << endl;
		cout << "Lowest Grade   :  " << grading.getLowestGrade() << endl;
		cout << "---------" << endl;
		cout << endl;
		cout << "Someone Else, To Calculate(Y/N) : "; cin >> again;
		again = tolower(again);
		if (again == 'y') {
			cout << endl; cout << endl;
			cout << "___________________________________" << endl;
			cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
			cout << endl;
		}
	} while (again == 'y');
	return 0;
}

int validateNumbers() {
	int a;
	cout << "Enter Again : "; cin >> a;
	return a;
}