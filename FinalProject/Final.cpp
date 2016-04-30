#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "market.h"

using namespace std;


int menu()
{
	//visual menu
	cout << "======Main Menu======" << endl;
	cout << "1. Print Inventory" << endl;
	cout << "2. Time Statistics" << endl;
	cout << "3. Buy a Product" << endl;
	cout << "4. Net profit"	<< endl;
	cout << "5. Add Money to Wallet"	<< endl;
	cout << "6. Quit" << endl; 
	
	//converting the users choice
	int choice;
	string choiceS;
	getline(cin,choiceS);
	stringstream choiceConvert(choiceS);
	choiceConvert >> choice;
	
	return choice;
}

void newSettings(market * coinMarket)
{
	//opening the settings file
	string settings = "settings.txt";
	ifstream settingsFile;
	settingsFile.open(settings.c_str());
	
	//If file opening doesn't work this happens 
	if(!settingsFile)
	{
		cout << "settings opening unsuccessful" << endl;
	}
	//parsing the file 
	
	//initalizing the variables
	//____s versions of names is where the getline of the variable is stored before being converted
	double decay;
	string decayS;	
	double decayBase;
	string decayBaseS;
	bool recency;
	string recencyS;
	bool max;
	string maxS;
	double maxP;
	string maxPS;
	double postMultiplier;
	string postMultiplierS;
	
	//storing the settigns in the string versions of the settings
	getline(settingsFile,decayS);
	// the : version of the getline storage gets rid of all of the
	//     text before the : without changing the value
	getline(settingsFile,decayS,':');  
	getline(settingsFile,decayS);
	getline(settingsFile,decayBaseS,':');
	getline(settingsFile,decayBaseS);
	getline(settingsFile,recencyS,':');
	getline(settingsFile,recencyS);
	getline(settingsFile,maxS,':');
	getline(settingsFile,maxS);
	getline(settingsFile,maxPS,':');
	getline(settingsFile,maxPS);
	getline(settingsFile,postMultiplierS,':');
	getline(settingsFile,postMultiplierS);
	
	//Converting all of the strings to the appropriate type
	stringstream decayConvert(decayS);
	decayConvert >> decay;
	stringstream decayBaseConvert(decayBaseS);
	decayBaseConvert >> decayBase;
	stringstream recencyConvert(recencyS);
	recencyConvert >> recency;
	stringstream maxConvert(maxS);
	maxConvert >> max;
	stringstream maxPConvert(maxPS);
	maxPConvert >> maxP;
	stringstream postMultiplierConvert(postMultiplierS);
	postMultiplierConvert >> postMultiplier;
	
	//Setting the settings values
	coinMarket->addSettings(decay,decayBase,recency,max,maxP,postMultiplier);
	
}

void newProducts(market * coinMarket)
{
	//opening the products file
	string products = "Products.txt";
	ifstream productsFile;
	productsFile.open(products.c_str());
	
	//If file opening doesn't work this happens 
	if(!productsFile)
	{
		cout << "file opening unsuccessful " << endl;
	}
	string inLine;
	getline(productsFile,inLine);
	while(!productsFile.eof())
	{
		string name;
		//____s versions of names is where the getline of the variable is stored before being converted
		int quantity;
		string quantityS;
		double price;
		string priceS;
		double cost;
		string costS;
		
		//parsing the line
		getline(productsFile,name,',');
		getline(productsFile,quantityS,' ');
		getline(productsFile,priceS,' ');
		getline(productsFile,costS);
		
		//converting the varibles
		stringstream quantityConvert(quantityS);
		quantityConvert >> quantity;
		
		stringstream priceConvert(priceS);
		priceConvert >> price;
		
		stringstream costConvert(costS);
		costConvert >> cost;
		
		//giving it to the addProduct method
		if(name != "")
		{
			coinMarket->addProducts(name,quantity,price,cost);
		}
	}
}

void newUser(market *coinMarket)
{
	cout << "What is your name?" << endl;
	string userName;
	//password is unused scrapped idea
	string password = "password";
	
	//getting wallet info
	getline(cin,password);	cout << "How much is in your wallet? " << endl;
	double wallet;
	string walletS;
	getline(cin,walletS);
	stringstream walletConvert(walletS);
	walletConvert >> wallet;
	
	//runnign the addUser method multiple users scrapped
	coinMarket->addNewUser(userName,password, wallet);
}
int main(int argc, char **argv)
{
	//initializing the class
	market *coinMarket = new market();
	newSettings(coinMarket);
	newProducts(coinMarket);
	newUser(coinMarket);
	
	//menu loop
	bool interfaceKill = 0;
	while(!interfaceKill)
	{
		int choice = menu();
		switch(choice)
		{
			case 1:
			{
				//Printing products
				coinMarket->printProductsSafe();
				break;
			}
			case 2:
			{
				//giving the some past data about the time 
				coinMarket->timeStats();
				break;
			}
			case 3:
			{
				//buying the product
				cout << "Enter a Coin:" << endl;
				string coinName;
				getline(cin,coinName);
				coinMarket->buyProduct(coinName);
				break;
			}
			case 4:
			{
				//checking the differences between the purchase price and the cost of each coin
				coinMarket->totalProfit();
				break;
			}
			case 5:
			{
				//adding money to the current user's wallet
				coinMarket->addMoney();
				break;
			}
			case 6:
			{
				//ending the program
				interfaceKill = 1;
				break;
			}
		}
		
	}
	
	return 0;
	
}
