#include<iostream>
#include<string>
#include "CalculateGrade.h"
using namespace std;

string CalculateGrade::checkGradeMarks(int a) {
	if (a >= 90 && a < 100)
		return "A+";
	else if (a < 90 && a >= 85)
		return "A";
	else if (a >= 80 && a < 85)
		return "A-";
	else if (a < 80 && a >= 77)
		return "B+";
	else if (a < 77 && a >= 75)
		return "B";
	else if (a < 75 && a >= 70)
		return "B";
	else if (a < 70 && a >= 65)
		return "C+";
	else if (a < 65 && a >= 60)
		return "C";
	else if (a < 60 && a >= 55)
		return "C-";
	else if (a < 55 && a >= 50)
		return "D";
	if (a < 50)
		return "F";
}

CalculateGrade::CalculateGrade() {
	studentName = "";
	allGrades = nullptr;
	numberOfGrades = 0;
	subjectMarks = nullptr;
	averagedGrade = 'O';
}
CalculateGrade::CalculateGrade(string nam, int total) {
	studentName = nam;
	numberOfGrades = total;
	subjectMarks = new int[numberOfGrades];
	allGrades = new string[numberOfGrades];
	averagedGrade = 'O';
}

//Setters
void CalculateGrade::setStudentName(string nam) {
	studentName = nam;
}
void CalculateGrade::setTotalGrades(int a) {
	numberOfGrades = a;
	allGrades = new string[numberOfGrades];
}
void CalculateGrade::setGrades() {
	for (int i = 0; i < numberOfGrades; i++) {
		allGrades[i] = checkGradeMarks(subjectMarks[i]);
	}
}
void CalculateGrade::setMarks(int marks, int index) {
	if (index >= 0 && index < numberOfGrades)
		subjectMarks[index] = marks;
	else
		cout << "Index Is Out Of Range!!" << endl;
}

//Getters
string CalculateGrade::getStudentName()const {
	return studentName;
}
int CalculateGrade::getTotalNumberOfGrades()const {
	return numberOfGrades;
}
string CalculateGrade::getGrades(int index) {
	if (index >= 0 && index < numberOfGrades)
		return allGrades[index];
	else
		cout << "Invalid Grade's Index" << endl;
}
int CalculateGrade::getMarks(int index)const {
	if (index >= 0 && index < numberOfGrades)
		return subjectMarks[index];
	else
		cout << "Invalid Mark's Index" << endl;
}

//Main Utility Functions
string CalculateGrade::getAveragedGrade() {
	double sum = 0;
	for (int i = 0; i < numberOfGrades; i++) {
		sum += subjectMarks[i];
	}

	double averageMarks = sum / numberOfGrades;
	averagedGrade = checkGradeMarks(averageMarks);
	return averagedGrade;
}
string CalculateGrade::getHighestGrade() {
	double highest = subjectMarks[0];
	for (int i = 0; i < numberOfGrades; i++) {
		if(subjectMarks[i] > highest)
			highest = subjectMarks[i];
	}

	string highestGrade = checkGradeMarks(highest);
	return highestGrade;
}
string CalculateGrade::getLowestGrade() {
	double lowest = subjectMarks[0];

	for (int i = 0; i < numberOfGrades; i++) {
		if (subjectMarks[i] < lowest)
			lowest = subjectMarks[i];
	}

	string lowestGrade = checkGradeMarks(lowest);
	return lowestGrade;
}