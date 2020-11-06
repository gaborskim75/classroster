#include<iostream>
#include<iomanip>
#include<string>
#include "degree.h"
#include "student.h"
using namespace std;

//Empty constructor
Student::Student() {

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	this->numDays = new int[numDaysArray];
	for (int i = 0; i < numDaysArray; i++) this->numDays[i] = 0;
	this->dprog = UNDECLARED;
}

//Full constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram prog) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->numDays = new int[numDaysArray];
	for (int i = 0; i < numDaysArray; i++) this->numDays[i] = numDays[i];
	this->dprog = prog;
}

//getters
string Student::getID() {

	return studentID;
}

string Student::getFirstName() {

	return firstName;
}

string Student::getLastName() {

	return lastName;
}

string Student::getEmail() {

	return email;
}

int Student::getAge() {

	return age;
}

int* Student::getnumDays() {

	return numDays;
}

DegreeProgram Student::getDegreeProgram() {

	return dprog;
}

//setters
void Student::setID(string studentID) {

	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {

	this->firstName = firstName;
}

void Student::setLastName(string lastName) {

	this->lastName = lastName;
}

void Student::setEmail(string email) {

	this->email = email;
}

void Student::setAge(int age) {

	this->age = age;
}

void Student::setNumDays(int numDays[]) {

	this->numDays = new int[numDaysArray];
	for (int i = 0; i < numDaysArray; i++)
		this->numDays[i] = numDays[i];
}

void Student::setDegreeProgram(DegreeProgram d) {

	this->dprog = d;
}

//print student data
void Student::print() {

	cout << getID() << "\t";
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Email: " << getEmail() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "Days in Course: {" << numDays[0] << ", ";
	cout << numDays[1] << ", ";
	cout << numDays[2] << ",}\t";
	cout << "Degree Program: " << degreeProgramStrings[getDegreeProgram()] << "\n";
}

//destructor
Student::~Student() {

	if (numDays != nullptr) {
		delete[] numDays;
		numDays = nullptr;
	}
}

