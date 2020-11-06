#pragma once
#include <string>
#include "degree.h"
using namespace std;

//D1. class
class Student {

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* numDays;
	DegreeProgram dprog;

public:
	const static int numDaysArray = 3;

	//D2.d. Constructor
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram prog);

	//D2.a. accessors (getters)
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getnumDays();
	DegreeProgram getDegreeProgram();
	
	//D2.b. mutators (setters)
	void setID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumDays(int numDays[]);
	void setDegreeProgram(DegreeProgram d);

	//D2.c. All external access and changes to any instance variables are done using accessors and mutators.

	//D2.e. print specific student data
	void print();

	//destructor
	~Student();
};

