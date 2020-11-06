#include <iostream>
#include <iomanip>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

Roster::Roster() {
	this->maxSize = 0;
	this->lastStudent = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int maxSize) {
	this->maxSize = maxSize;
	this->lastStudent = -1;
	this->classRosterArray = new Student * [maxSize];
}

void Roster::parse_Add(string data) {

	if (lastStudent < maxSize) {
		lastStudent++;

		int narray[Student::numDaysArray];
		
		if (data[0] == 'A')
		{
			this->classRosterArray[lastStudent] = new Student();
		}
		else
		{
			cerr << "INVALID STUDENT ID! EXITING!\n";
			exit(-1);
		}
		
		
		int rSide = studentData[lastStudent].find(",");
		classRosterArray[lastStudent]->setID(studentData[lastStudent].substr(0, rSide));

		int lSide = rSide + 1;
		rSide = studentData[lastStudent].find(",", lSide);
		classRosterArray[lastStudent]->setFirstName(studentData[lastStudent].substr(lSide, rSide - lSide));

		lSide = rSide + 1;
		rSide = studentData[lastStudent].find(",", lSide);
		classRosterArray[lastStudent]->setLastName(studentData[lastStudent].substr(lSide, rSide - lSide));

		lSide = rSide + 1;
		rSide = studentData[lastStudent].find(",", lSide);
		classRosterArray[lastStudent]->setEmail(studentData[lastStudent].substr(lSide, rSide - lSide));

		lSide = rSide + 1;
		rSide = studentData[lastStudent].find(",", lSide);
		int age = stoi(studentData[lastStudent].substr(lSide, rSide - lSide));

		classRosterArray[lastStudent]->setAge(age);

		lSide = rSide + 1;
		rSide = studentData[lastStudent].find(",", lSide);
		narray[0] = stoi(studentData[lastStudent].substr(lSide, rSide - lSide));

		lSide = rSide + 1;
		rSide = studentData[lastStudent].find(",", lSide);
		narray[1] = stoi(studentData[lastStudent].substr(lSide, rSide - lSide));

		lSide = rSide + 1;
		rSide = studentData[lastStudent].find(",", lSide);
		narray[2] = stoi(studentData[lastStudent].substr(lSide, rSide - lSide));

		classRosterArray[lastStudent]->setNumDays(narray);

		lSide = rSide + 1;
		rSide = studentData[lastStudent].find(",", lSide);
		string degProgString = string(studentData[lastStudent].substr(lSide, rSide - lSide));
		char lastChar = degProgString.back();
		if (lastChar == 'K')
		{
			classRosterArray[lastStudent]->setDegreeProgram(NETWORK);
		}
		else if (lastChar == 'Y')
		{
			classRosterArray[lastStudent]->setDegreeProgram(SECURITY);
		}
		else if (lastChar == 'E')
		{
			classRosterArray[lastStudent]->setDegreeProgram(SOFTWARE);
		}
		else 
		{
			classRosterArray[lastStudent]->setDegreeProgram(UNDECLARED);
		}
	}
	else {

		cerr << "ERROR. LIST HAS EXCEEDED MAX SIZE.\n EXITING.";
		exit(-1);

	}
}

void Roster::printAll() {

	for (int i = 0; i <= this->lastStudent; i++) (this->classRosterArray)[i]->print();

}

bool Roster::remove(string studentID) {

	bool found = false;
	for (int i = 0; i <= lastStudent; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastStudent];
			lastStudent--;
		}
	}
	return found;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastStudent; i++)
	{
		if (this->classRosterArray[i]->getID() == studentID)
		{
			found = true;
			int* d = classRosterArray[i]->getnumDays();
			cout << "Average number of days for student " << studentID << " is " << (d[0] + d[1] + d[2]) / 3 << "\n";
		}
	}
	if (!found) cout << "Student not found.\n";
}

void Roster::printInvalidEmails()
{
	cout << "Invalid emails:\n";
	//for (int i = 0; i <= lastStudent; i++)
	//{
	//	cout << "Student ID: " << classRosterArray[i]->getID() << ": ";
	//	string badEmail = classRosterArray[i]->getEmail();
	//	if ((badEmail.find("@") == string::npos || badEmail.find(".") == string::npos) || (badEmail.find(" ") != string::npos))
	//	{
	//		cout << badEmail << "\n";
	//	}
	//}

	for (int i = 0; i <= lastStudent; i++)
	{
	
		string badEmail = classRosterArray[i]->getEmail();
		if ((badEmail.find("@") == string::npos || badEmail.find(".") == string::npos) || (badEmail.find(" ") != string::npos))
		{
			cout << "Student ID: " << classRosterArray[i]->getID() << ": " << badEmail << "\n";
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree)
{
	cout << "Printing students sorted by degree program: " << degreeProgramStrings[degree] << "\n";
	for (int i = 0; i <= lastStudent; i++)
	{
		if (this->classRosterArray[i]->getDegreeProgram() == degree) this->classRosterArray[i]->print();
	}
}

Roster::~Roster()
{
	for (int i = 0; i < totalStudents; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}