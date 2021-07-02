#include <iostream>
#include <fstream>

using namespace std;

class UserLogin
{
 public:

    UserLogin()
    {
        loginSuccess = 0;
    }
    void login()
    {
        cout << "Welcome to our scheduling system. Please log in to continue!";
        cout << "Username: ";
        cin >> userNameAttempt;

        userName = getFile(""); //some data file can be inpu here

        if(userNameAttempt == userName)
        {
            cout << "Password:";
            cin >> passwordAttempt;

            passWord = getFile("");/// some data file can be input here

            if(passwordAttempt == passWord)
            {
                cout << "Valid Login. Hello there!";
                cin.get();
            }
            else
            {
                cout << "Wrong password" << endl;
                login();
            }
        }
        else
        {
            cout << "User not found" << endl;
            login();
        }
    }

    string getFile(const char* p_fileName)
    {
        string line;
        fstream file;

        int encryptedChar;

        file.open(p_fileName, ios::in);
        
        while(1)
        {
            file >> encryptedChar;
            if(encryptedChar == 0)
            {
                file.close();
                return line;
            }
            line += (char)decrypt(encryptedChar);
        }
    }

    void saveFile(string p_line, const char* p_fileName) //Implemented simple local file 
    {
        fstream file;
        file.open(p_fileName, ios::out);

        for(int i = 0; i < p_line.length(); i++)
        {
            file << encrypt(p_line[i]);
            file << "\n";
        }

        file << "0";
        file.close();
    }

    int encrypt(int p_letter)
    {
        return p_letter + 3;   
    }
    int decrypt(int p_letter)
    {
        return p_letter - 3;
    }

private:
    string passWord;
    string userName;
    string userNameAttempt;
    string passwordAttempt;
    bool loginSuccess;
};

int main()
{
    UserLogin app;
    app.login();

    cin.get();
}