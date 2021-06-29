#include <iostream> 
#include <sqlite3.h> 
#include <string> 
#include <stdio.h>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");

    return 0;
}

int main(int argc, char** argv)
{
	sqlite3* DB;

	/*******************************************************************
	 Creating a table
	 Create a string then pass the string into the sqlite3_exec function
	********************************************************************/
	string table = "CREATE TABLE COURSE"
		"CRN INTEGER PRIMARY KEY, "
		"TITLE TEXT NOT NULL, "
		"department TEXT NOT NULL, "
		"time NUMERIC NOT NULL); "
		"day(s) TEXT NOT NULL, "
		"semester TEXT NOT NULL, "
		"year INTEGER NOT NULL, "
		"credits INTEGER NOT NULL, ";

	int exit = 0;

	exit = sqlite3_open("assignment3 (2).db", &DB);			//open the database

	char* messageError;

	// execute the create table command
	// sqlite3_exec( pointer to database file, string for sql command, callback function (used to respond to queries, not used here), input to callback, error message address)
	exit = sqlite3_exec(DB, table.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK)
	{
		std::cerr << "Error Create Table" << std::endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Table created Successfully" << std::endl;


	/*******************************************************************
	 Inserting values into a table.
	 Create a string then pass the string into the sqlite3_exec function
	********************************************************************/
	// hard-code (push) a few values into the database - NOTE you can create a single string with multiple INSERT commands
	string sql("INSERT INTO COURSE(1, 'History', 'HUSS', 2, 'MF', 'spring', 1999, 4);"
		"INSERT INTO COURSE(2, 'Appl.P', 'BSCO', 2, 'WF', 'spring', 1944, 4);"
		"INSERT INTO COURSE(3, 'CmpSci1', 'BCOS', 2, 'MW', 'spring', 2019, 4);"
		"INSERT INTO COURSE(4, 'Physics', 'BSAS', 2, 'TTH', 'spring', 1615, 4);"
		"INSERT INTO COURSE(5, 'NetwkT', 'BSCO', 2, 'MW', 'spring', 1830, 4);"
		"INSERT INTO STUDENT(10011, 'Tim', 'Williams', 1999, 'BSEN', 'williamst');"
		"INSERT INTO STUDENT(10012, 'Tom', 'Thomas', 2019, 'BSEN', 'thomast');"
	);

	// execute the command
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK)
	{
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(messageError);
	}
	else
		std::cout << "Records created Successfully!" << std::endl;



	/***********************************************
	 print all data in the table with SELECT * FROM
	 create string with query then execute
	 **********************************************/
	string query = "SELECT * FROM ADMIN, COURSE, INSTRUCTOR, STUDENT;";

	cout << endl << query << endl;		//print the string to screen

	// you need the callback function this time since there could be multiple rows in the table
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);



	/**********************************************
	Delete instructor
	**********************************************/
	string query = "DELETE FROM INSTRUCTOR WHERE ID = 20006;";

	exit = sqlite3_exec(DB, userInput.c_str(), callback, NULL, NULL);

	string query = "UPDATE ADMIN SET TITLE = 'Vice-President' WHERE ID = 30002";

	exit = sqlite3_exec(DB, userInput.c_str(), callback, NULL, NULL);
	/***********************************
	 SELECT example
	 
	***********************************/
	string query = "SELECT COURSE.title, instructor.name, instructor.dept FROM COURSE, instructor WHERE COURSE.department = instructor.dept";
	exit = sqlite3_exec(DB, userInput.c_str(), callback, NULL, NULL);
	sqlite3_close(DB);
	return 0;
}
