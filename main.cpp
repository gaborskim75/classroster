#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include "roster.cpp"
#include "student.cpp"
using namespace std;

int main() {
	
	cout << "C867: Scripting and Programming - Applications\n";
	cout << "Programming Language: C++\n";
	cout << "Van Randon, 838666\n\n";

	Roster* ros = new Roster(totalStudents);
	cout << "Building student roster...\t";
	for (int i = 0; i < totalStudents; i++)
	{
		ros->parse_Add(studentData[i]);
	}
	cout << "COMPLETE.\n";
	cout << "Listing all students...\n\n";
	ros->printAll();	

	ros->printAverageDaysInCourse("A1");

	ros->printInvalidEmails();

	ros->printByDegreeProgram(NETWORK);
	ros->printByDegreeProgram(SECURITY);
	ros->printByDegreeProgram(SOFTWARE);

	cout << "Removing A3...\n";
	if (ros->remove("A3")) ros->printAll();
	else cout << "Student not found\n";

	cout << "Removing A3...\n";
	if (ros->remove("A3")) ros->printAll();
	else cout << "Student not found\n";

	system("pause");
	return 0;
}