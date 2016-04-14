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
	cout << "1. Print vertices" << endl;
	cout << "2. Find districts" << endl;
	cout << "3. Find shortest path" << endl;
	cout << "4. Quit" << endl; 
	
	//converting the users choice
	int choice;
	string choiceS;
	getline(cin,choiceS);
	stringstream choiceConvert(choiceS);
	choiceConvert >> choice;
	
	return choice;
}

void newSettings(market sodaMarket)
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
	double decay;
	bool recency;
	bool max;
	double maxP;
	sodaMarket.addSettings(decay,recency,max,maxP);
	cout << "b" << endl;
	
}

void newProducts(market sodaMarket)
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
	string name;
	int quantity;
	double price;
	sodaMarket.addProducts(name,quantity,price);
	cout << "c" << endl;
}


int main(int argc, char **argv)
{
	market sodaMarket;
	newSettings(sodaMarket);
	newProducts(sodaMarket);
	bool interfaceKill = 0;
	while(!interfaceKill)
	{
		int choice = menu();
		switch(choice)
		{
			case 1:
			{
				cout << "1. Print vertices" << endl;
				break;
			}
			case 2:
			{
				cout << "2. Find districts" << endl;
				break;
			}
			case 3:
			{
				cout << "3. Find shortest path" << endl;
				break;
			}
			case 4:
			{
				cout << "4. Quit" << endl;
				break;
			}
		}
		
	}
	
	return 0;
	
}
