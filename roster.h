#pragma once
#include<string>
#include "degree.h"
#include "student.h"
using namespace std;

const int totalStudents = 5;

const string studentData[totalStudents] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Van,Randon,vrando5@wgu.edu,49,17,18,15,SOFTWARE",
};

class Roster {


public:
	int lastStudent;

	int maxSize;

	Student** classRosterArray;

	Roster();

	Roster(int maxSize);

	void parse_Add(string data);

	void printAll();

	bool remove(string studentID);

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram d);

	~Roster();
};

