#include <iostream>
#include<vector>
#include <fstream>
#include"projectcs103.h"

using namespace std;

void menu() {

	cout << "+++++++++++++Lunch Menu+++++++++++++++++++\n";
	cout << "1:Meat Wrap $" << itemPrice[1] << endl;
	cout << "2:Vegan Wrap $" << itemPrice[2] << endl;
	cout << "3:Chicken Sandwich $" << itemPrice[3] << endl;
	cout << "4:Veg Sandwich $" << itemPrice[4] << endl;
	cout << "5:Fruit Slices $" << itemPrice[5] << endl;
	cout << "6:Up and Go $" << itemPrice[6] << endl;
	cout << "7:Fruit and Nut Bar $" << itemPrice[7] << endl;
	cout << "8:Weekly Lunch Special(weekdays) $" << itemPrice[8] << endl;
	cout << "9:Monthly Lunch Special(weekdays) $" << itemPrice[9] << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++\n";

}

void printOrderTitle() {

	fstream lunchFile;

	lunchFile.open("ORDER_DATA.csv", ios::out);//write title for ORDER_DATA.csv
	if (lunchFile.is_open()) {
		lunchFile <<"User ID"  << "," << "Item Name" << " ,"
			<< "Unit Price" << " ,"
			<< "Quantity" << " ,"
			<< "Total Price" << endl;

		lunchFile.close();

	}
}