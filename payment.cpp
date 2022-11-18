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

