//John and Naomi's School Lunch ordering System
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include<vector>
#include<iomanip>
#include<chrono>
#include"projectcs103.h"


using std::fstream;
using namespace std;

//Main function
int main() {

	cout << "******************** Welcome to Naomi and John's School Lunch ordering System ********************\n\n";
	cout << "Please login (or create), to access your account and to order from the menu items.\n\n";

	//Login
	//User to select choice for login or register
	int choice;
	string userID;

	UserData customerData;//UserData customerData; //set up structure member

	cout << "Select a choice!\n1: Register\n2: Login\n Your choice: ";
	cin >> choice;
	//User to enter username and password	
	if (choice == 1) {

		cout << "Select a Username: ";
		cin >> customerData.userName;
		cout << "Select your Password: ";
		cin >> customerData.userPassword;


		userID = customerData.userName + customerData.userPassword;  // make userID
		customerData.userId = userID;

		printCustomerDataTitle(); //  Write title for CUSTOMER_DATA.csv

		fstream customerFile;	//save customer data
		customerFile.open("CUSTOMER_DATA.csv", ios::app);		
		if (customerFile.is_open()) {
			customerFile << customerData.userId << ","
				<< customerData.userName << ","
				<< customerData.userPassword;

			customerFile.close();
		}

		printInvoiceTitle(customerData.userId, customerData.userName);	//write invoice title for LUNCH_INVOICE.txt

		//Creates file for user
		ofstream file;
		file.open(customerData.userName + ".csv");
		file << customerData.userName << endl << customerData.userPassword;
		file.close();
		

		main();

	} else if (choice == 2) { //If user enters wrong credentials
		bool status = LoggingIn();
		if (!status) {
			cout << "Incorrect Information Entered!, Please Try Again!" << endl;
			system("PAUSE");
			return 0;
		}
		else { //Login successful
			cout << "Login Successful!\n";

			printOrderTitle();	//write title for ORDER_DATA.csv

			//utc_clock::time_point t = clock_cast<utc_clock>(file_clock::now());// compile using: /std:c++latest
			int lunchItemsCord;
			int quantity;//User to enter quantity wanted
			double totalItemPrice, totalAmount = 0.0;
			char answer;

			menu(); //display lunch menu

			do {
				cout << "Please enter your selection : ";
				cin >> lunchItemsCord;

				cout << "You have entered: ";
				switch (lunchItemsCord) { //Switch case for displaying selected lunch itemsmeatWrap,

				case meatWrap: cout << "Meat Wrap\n";

					break;
				case veganWrap: cout << "Vegan Wrap\n";

					break;
				case chickenSandwich: cout << "Chicken Sandwich\n";

					break;
				case vegSandwich: cout << "Veg Sandwich\n";

					break;
				case fruitSlices: cout << "Fruit Slices\n";

					break;
				case upandGo: cout << "Up And Go\n";

					break;
				case fruitandNutBar: cout << "Fruit And Nut Bar\n";

					break;
				case weeklySpecialOrder: cout << "Weekly Special lunch(weekdays)\n";

					break;
				case monthlySpecialOrder: cout << "Monthly Special lunch(weekdays)\n";

					break;
				}

				cout << "Please enter your Quantity: ";
				cin >> quantity;

				totalItemPrice = itemPrice[lunchItemsCord] * quantity; //caluculate item price total 
				totalAmount = totalAmount + totalItemPrice;				// calucultet amount total

				cout << "You have selected: "
					<< enum_str[lunchItemsCord] << " $" << itemPrice[lunchItemsCord] << " x "
					<< quantity << "	Totalprice $" << totalItemPrice << endl;


				fstream invoice;

				invoice.open("LUNCH_INVOICE.txt", ios::app);	//order items into LUNCH_INVOICE.txt for Invoice
				if (invoice.is_open()) {
					invoice << left << setw(32) << enum_str[lunchItemsCord]
							<< right << setw(12) << "$" << itemPrice[lunchItemsCord]
							<< setw(15) << quantity
							<< right << setw(13) << "$" << totalItemPrice << endl;
				}
				invoice.close();

				fstream lunchFile;

				lunchFile.open("ORDER_DATA.csv", ios::app);		//order items into ORDER_DATA.csv
				if (lunchFile.is_open()) {
					lunchFile<< userID <<"," 
							 << enum_str[lunchItemsCord] << ","
							 << itemPrice[lunchItemsCord] << ","
							 << quantity << ","
							 << totalItemPrice << endl;

					lunchFile.close();
				}

				cout << "Would you like to choose anything else?(y/n) :";
				cin >> answer;
			} while (answer == 'y');

			printDiscount(totalAmount); // disscount caluculation
			
			printInvoice(); // make invoice with txtfile

			int paymentType = 0;	//payment content
			char saveNo;

			Creditcard credit;

			cout << "\n\n********** Payment Type **********" << endl;
			cout << "  1 : Credit card" << endl;
			cout << "  2 : Bank Account" << endl;
			cin >> paymentType;


			if (paymentType == 1) {
				cout << "Please enter your credit card number : ";

				cin >> credit.cardNumber;

				int n = credit.cardNumber.length();

				if (checkLuhn(credit.cardNumber) && n >= 14) {

					cout << "Please enter the expiry date" << endl;
					cout << "Month(XX) : ";
					cin >> credit.monthOfExpire;
					cout << "Year (20XX): ";
					cin >> credit.yearOfExpire;

					if (credit.yearOfExpire < 22 && credit.monthOfExpire < 11) { //Date November/2022 now
						invalidnumber();

						exit(0);
					}
					else {
						cout << "please enter CVV number : ";
						cin >> credit.cvvNumber;

						cout << "Thank you for purchesing our lunch service. We are prosessing now...\n";

						cout << "Would you like to save the card number? (y/n) : ";
						cin >> saveNo;

						if (saveNo == 'y') {
							//save cardnumbers into customer.csv 
							
							printCreditTitle(); //23customer credit data title
							printCredit(userID, credit.cardNumber, credit.monthOfExpire, credit.yearOfExpire);	//customer credit data
						}
					}
				}
				else {
					invalidnumber();
				}

			}
			else if (paymentType == 2) {
				cout << "Please enter your Email address: ";
				cin >> customerData.emailAddress;

				fstream customerFile;	//save email address to customer data
				customerFile.open("CUSTOMER_DATA.csv", ios::app);


				if (customerFile.is_open()) {
					customerFile << "," << customerData.emailAddress << endl;
				}
					customerFile.close();

				cout << "Thank you for ordering our lunch service. we are going to send invoice soon." << endl;
			}

			if (answer == 'n') {				//log out 
				cout << "You have logged out, Program will close now";
			//	exit(0); 
			}
		}
	}
	system("pause>0");
}
	

