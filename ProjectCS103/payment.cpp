#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include<vector>
#include"projectcs103.h"

bool checkLuhn(const string& cardNo) { //Luhn algorithm for creditcard

	int nDigits = cardNo.length();

	int nSum = 0, isSecond = false;

	for (int i = nDigits - 1; i >= 0; i--) {

		int d = cardNo[i] - '0';

		if (isSecond == true) {

			d = d * 2;

			nSum += d / 10;
			nSum += d % 10;

			isSecond = ~isSecond;
		}
	}
	return (nSum % 10 == 0);
}

void invalidnumber() {
	cout << "This is invalid number, please try again" << endl;
}

void printCreditTitle() { //customer credit data title

	fstream creditFile;

	creditFile.open("CREDIT_NUM_DATA.csv", ios::out);

	if (creditFile.is_open()) {
		creditFile << "User ID" << "," << "Card Number" << "," << "Expire Month" << ","
			<< "Expire Year" << endl;

		creditFile.close();

	}
}
void printCredit(string& userID, string& cardNumber, int& monthOfExpire, int& yearOfExpire) {	//customer credit data
	
	fstream creditFile;

	creditFile.open("CREDIT_NUM_DATA.csv", ios_base::app);
	creditFile << userID << "," << cardNumber << "," << monthOfExpire << "," << yearOfExpire << endl;

	if (!creditFile) {
		cerr << "Error" << endl;  // Error message if couldn"t open ofs
		creditFile.close();
	}
}

