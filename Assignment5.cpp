#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
public:
	void setfn(string fn) {
		f_n = fn;
	}
	string getfn() {
		return f_n;
	}
	void setln(string ln) {
		l_n = ln;
	}
	string getln() {
		return l_n;
	}
	void setID(int CID) {
		ID = CID;
	}
	int getID() {
		return ID;
	}
	void displayInfo(string info, string info2, int i) {
		cout << "The first name is " << f_n << endl;
		cout << "The Last name is " << l_n << endl;
		cout << "The ID number is " << ID << endl;
	}
private:
	string f_n;
	string l_n;
	int ID;
};

class Course {
public:
	int CRN;
	string title;
	string department;
	string dayOfWeek;
	string semester;
	int year;
	int credits;

};

string removeCourse() {
	int CRN;
	cout << "What is the CRN of the course you'd like to delete?" << endl;
	cin >> CRN;

	void student::removeCourse() {
		cout << "What course do you want to drop?" << endl;
	}

	string query = "DELETE FROM INSTRUCTOR WHERE ID = CRN;";

}

string addCourse() {
	int CRN;
	string title;
	string department;
	string dayOfWeek;
	string semester;
	int year;
	int credits;
	string addCourse;
	cout << "What will the CRN of the course be?" << endl;
	cin >> CRN;
	cout << "What will the title of the course be?" << endl;
	cin >> title;
	cout << "What will the department be?" << endl;
	cin >> department;
	cout << "What days of the week will the course be during (ex. MW, TTH, MF)" << endl;
	cin >> dayOfWeek;
	cout << "What semester will it be during?" << endl;
	cin >> semester;
	cout << "What year is the class during?" << endl;
	cin >> year;
	cout << "How many credits is the class?" << endl;
	cin >> credits;

	student::student(string fName, string lName, int id)
		:user{ fName, lName, id } {}

	void student::searchCourse() {
		cout << "What course are you looking for?" << endl;
	}

	void student::addCourse() {
		cout << "What course do you want to add?" << endl;
	}


	string addCourse = "INSERT INTO COURSE(CRN, title, department, dayOfWeek, semester, year, credits)";
	return addCourse;
}

class student : public User {
public:
	char userInput;

	void studentMessage() {
		cout << "Welcome student!" << getln << "What would you like to do?" << endl;
		cin >> userInput;

		switch (userInput) {
		case 'S':

		case 'A':

		case 'P':
		}
	}
};

class instructor : public User {
public:
	char userInput;
	void instructorMessage() {
		cout << "Welcome Instructor " << getln << "What would you like to do?" << endl;

		switch (userInput) {
		case 'P':

		case 'C':

		case 'S':
		}
	}
};

class IDnum : public User {
public:
	char userInput;
	int userInput2;
	void IDnumMessage() {
		cout << "Welcome IDnum " << getln << "What would you like to do?" << endl;
		cin >> userInput;
		switch (userInput) {
		case 'A':
			cout << "Do you want to remove or add a course? (1 to add a course and 2 to remove" << endl;
			cin >> userInput2;
			if (userInput2 == 1) {
				addCourse();
				string sql(addCourse());
			}
			else {
				removeCourse();
			}

		case 'U':

		case 'S':

		case 'P':
		}
	}
};

int main() {

	User user1;
	student student1;
	instructor instructor1;
	IDnum IDnum1;

	user1.setfn("Gary");
	user1.setln("Williams");
	user1.setID(8189);
	user1.displayInfo(user1.getfn(), user1.getln(), user1.getID());
	student1.studentMessage();

	instructor1.instructorMessage();

	IDnum1.IDnumMessage();

}

static int callback(void* data, int argc, char** argv, char** azColName)
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");

	void student::printSchedule() {
		cout << "Printing schedule" << endl;
	}

	return 0;
}