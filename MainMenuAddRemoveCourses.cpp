#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
public:
	void setfName(string fName) {
		f_name = fName;
	}
	string getfName() {
		return f_name;
	}
	void setlName(string lName) {
		l_name = lName;
	}
	string getlName() {
		return l_name;
	}
	void setID(int ID1) {
		ID = ID1;
	}
	int getID() {
		return ID;
	}
	void displayInfo(string info, string info2, int i) {
		cout << "The first name is " << f_name << endl;
		cout << "The Last name is " << l_name << endl;
		cout << "The ID number is " << ID << endl;
	}
private:
	string f_name;
	string l_name;
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

	
	string addCourse = "INSERT INTO COURSE(CRN, title, department, dayOfWeek, semester, year, credits)";
	return addCourse;
}

class student : public User {
public:
	char userInput;
	
	void studentMessage() {
		cout << "Welcome student!" << getlName << "What would you like to do? Type S to search courses, Type A to add/drop courses, and P to print schedule (Case sensistive)" << endl;
		cin >> userInput;
	
		switch (userInput) {
		case 'S':
			//Start search course function

		case 'A':
			//start add/remove courses
		
		case 'P':
			// start print schedule;
		}
	}
};

class instructor : public User {
public:
	char userInput;
	void instructorMessage() {
		cout << "Welcome Instructor "  << getlName << "What would you like to do? Type P to print schedule, Type C to print classlist, and type S to search for courses (Case sensistive)" <<  endl;
		cin >> userInput;

		switch (userInput) {
		case 'P':
			//Start print schedule function

		case 'C':
			//start print classlist function

		case 'S':
			// start search course function
		}
	}
};

class admin : public User {
public:
	char userInput;
	int userInput2;
	void adminMessage() {
		cout << "Welcome Admin " << getlName << "What would you like to do? Type A to add/remove courses from the system, Type U add/remove users, type S to add/remove student, and P to search and print rosters and courses (Case sensistive)" << endl;
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
			//start add/remove users function

		case 'S':
			// start add/remove student

		case 'P':
			//start print rosters and courses function
		}
	}
};

int main() {

	User user1;
	student student1;
	instructor instructor1;
	admin admin1;

	user1.setfName("Gary");
	user1.setlName("Williams");
	user1.setID(8189);
	user1.displayInfo(user1.getfName(), user1.getlName(), user1.getID());
	student1.studentMessage();

	instructor1.instructorMessage();

	admin1.adminMessage();

}