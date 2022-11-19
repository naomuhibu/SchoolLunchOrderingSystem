#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include<vector>
#include<iomanip>
#include"projectcs103.h"

using namespace std;

void printInvoiceTitle(string& userID, string& userName) {

	fstream invoice;
	invoice.open("LUNCH_INVOICE.txt", ios::out);	//write invoice for LUNCH_INVOICE.txt

	if (invoice.is_open()) {
		invoice << "***********************************************************************************************\n"
			<< "*************************     Naomi and John's School Lunch invoice      **********************\n\n"
			<< "***********************************************************************************************\n\n\n"
			//<< "\tDate : " << t << endl
			<< "\tCustomer ID : " << &userID << "\t" //do not show user ID for customer 
			<< "\tCustomer's Name : " << userName << endl	
			<< "___________________________________________________________________________________________________\n"
			<< "| Item name\t\t\t" << "|" << " Unit Price\t" << "|" << " Quantity\t" << "|" << " Total Price\t|" << endl
			<< "---------------------------------------------------------------------------------------------------\n";
	}
	invoice.close();
}

void printDiscount(double& totalAmount) {

	fstream invoice;
	invoice.open("LUNCH_INVOICE.txt", ios::app);  //write discount total

	if (invoice.is_open()) {

		double discount = 0.0, discountTotal, taxTotal;

		invoice << "***********************************************************************************\n"
			<< "Total : $" << totalAmount << endl;
		if (totalAmount >= 200) {
			discount = totalAmount * 0.1;
			invoice << "10% discount : $" << discount << "\t";
		}
		else if (totalAmount < 200 && totalAmount >= 50) {
			discount = totalAmount * 0.05;
			invoice << "5% discount : $" << discount << "\t";
		}

		discountTotal = totalAmount - discount;

		invoice << "Total Amount : $" << fixed << setprecision(2) << discountTotal << endl;
		taxTotal = discountTotal * 1.15;
		invoice << "Total Amount with GST : $" << fixed << setprecision(2) << taxTotal <<endl;
		invoice.close();

	}
}

void printInvoice() {
	fstream invoice;
	invoice.open("LUNCH_INVOICE.txt", ios::in);//read file
	if (invoice.is_open()) {
		string line;
		while (getline(invoice, line)) {
			cout << line << endl;
		}
		invoice.close();
	}
}