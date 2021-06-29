#include <iostream>
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

class student : public User {
	public: 
		void studentMessage() {
			cout << "student class Success" << endl;
		}
};

class instructor : public User {
	public:
		void instructorMessage() {
			cout << "instructor class Success" << endl;
		}
};

class admin : public User {
	public:
		void adminMessage() {
			cout << "admin class Success" << endl;
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