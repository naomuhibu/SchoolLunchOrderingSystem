#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include"projectcs103.h"

using namespace std;

//Login content
bool LoggingIn() {

	string user, pass;
	UserData userdata;

	cout << "Enter Username: "; cin >> userdata.userName; //Asks user for username
	cout << "Enter Your Password: "; cin >> userdata.userPassword; //Asks user for password

	ifstream read(userdata.userName + ".csv");
	getline(read, user);
	getline(read, pass);

	if (user == userdata.userName && pass == userdata.userPassword) { //If user enters correct username and password, returns true condition
		return true;
	}
	else { //Or returns false if credentials are not correct
		return false;
	}

	if (user == userdata.userName && pass == userdata.userPassword) {
		if (bool status = true) {

		}
	}
}


