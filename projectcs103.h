#pragma once
#include<vector>

using namespace std;

struct UserData {

	string userName;
	string userId;
	string userPassword;
	string emailAddress;

};

void printCustomerDataTitle(); //  Write title for CUSTOMER_DATA.csv

bool LoggingIn();

enum lunchItems {  //Enum created to store lunch items
	meatWrap = 1,
	veganWrap,
	chickenSandwich,
	vegSandwich,
	fruitSlices,
	upandGo,
	fruitandNutBar,
	weeklySpecialOrder,
	monthlySpecialOrder
};

static const char* enum_str[] = {
	"-",
	"meatWrap",
	"veganWrap",
	"chickenSandwich",
	"vegSandwich",
	"fruitSlices",
	"upandGo",
	"fruitandNutBar",
	"weeklySpecialOrder",
	"monthlySpecialOrder"

};

const vector <double> itemPrice = { 0,10.5,12,14.3,16,8.5,4,5.3,50,200 };

void printOrderTitle();

void menu();

struct Creditcard {

	string cardNumber;
	int monthOfExpire = 0;
	int yearOfExpire = 0;
	int cvvNumber = 0;

};

bool checkLuhn(const string& cardNo);

void invalidnumber();

void printInvoiceTitle(string& userID, string& userName);

void printDiscount(double& totalAmount);

void printCreditTitle(); //customer credit data title

void printCredit(string& userID, string& cardNumber, int& monthOfExpire, int& yearOfExpire);	//customer credit data

void printInvoice();
