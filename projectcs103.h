#pragma once
#include<vector>

using namespace std;

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

void menu();


struct UserData {

	string userName;
	string userId;
	string userPassword;
	string emailAddress;
};

struct Creditcard {

	string cardNumber;
	int monthOfExpire;
	int yearOfExpire;
	int cvvNumber = 0;
};

bool checkLuhn(const string& cardNo);

void invalidnumber();

void PrintInvoiceTitle(string& userId, string& userName);

void PrintOrderTitle();

void PrintDiscount(double &totalAmount);

