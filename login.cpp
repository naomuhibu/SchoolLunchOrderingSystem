#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include"projectcs103.h"

using namespace std;

//Login content
bool LoggingIn() {

	string user, pass;
	UserData loginData;

	cout << "Enter Username: "; cin >> loginData.userName; //Asks user for username
	cout << "Enter Your Password: "; cin >> loginData.userPassword; //Asks user for password

	ifstream read(loginData.userName + ".csv");
	getline(read, user);
	getline(read, pass);

	if (user == loginData.userName && pass == loginData.userPassword) { //If user enters correct username and password, returns true condition
		return true;
	}
	else { //Or returns false if credentials are not correct
		return false;
	}

	if (user == loginData.userName && pass == loginData.userPassword) {
		if (bool status = true) {

		}
	}
}

/*		if (bool status = true) 
		{
				fstream lunchFile;
				lunchFile.open("ORDER_DATA.csv", ios::in);//read file
				if (lunchFile.is_open()) {
					string line;
					while (getline(lunchFile, line)) {
						cout << line << endl;
					}
					lunchFile.close();
				}
			system("PAUSE");
		}
*/
