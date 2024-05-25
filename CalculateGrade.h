#pragma once
#include<iostream>
#include<string>
using namespace std;

class CalculateGrade {
	string studentName;
	int* subjectMarks;
	string* allGrades;
	int numberOfGrades;
	string averagedGrade;

	//Private Function
	string checkGradeMarks(int a);

public:
	CalculateGrade();
	CalculateGrade(string nam, int total);

	//Setters
	void setStudentName(string nam);
	void setTotalGrades(int a);
	void setGrades();
	void setMarks(int marks, int index);
	
	//Getters
	string getStudentName()const;
	int getTotalNumberOfGrades()const;
	string getGrades(int index);
	int getMarks(int index)const;

	//Other Utility Function
	string getAveragedGrade();
	string getHighestGrade();
	string getLowestGrade();
};