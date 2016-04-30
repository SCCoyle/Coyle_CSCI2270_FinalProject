#include "market.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>

market::market()
{
}

market::~market()
{
}
//unused method to check of the numbers a user inputs are double but all the user inputs ended up being 
//	getline() with doubles so there ws no longer a point to the method
int market::checkNumber(std::string number)
{
	int length = number.length();
	int nonSNumber;
	bool nonNumberChar = 0;
	for(int numberIndex = 0; numberIndex < length; numberIndex++)
	{
		bool currentCharNaN = 1;
		for(int numberToCheck = 1; numberToCheck < 11; numberToCheck++)
		{
			if(number[numberIndex] == numberToCheck)
			{
				currentCharNaN == 0;
			}
		}
		if(currentCharNaN)
		{
			nonSNumber = -1;
		}
	}
	if(number.length() > 10)
	{
		nonSNumber = -1;
	}
	else
	{
		std::stringstream convert(number);
		convert >> nonSNumber;
	}
	/*return codes 
	 * -1 not a number
	 * non negative number the number is actual number
	*/
	return nonSNumber;
}

void market::addProducts(std::string name,int quantity, double price, double cost)
{
	//allocating memory for a new product
	product *newProduct = new product(name,quantity,price,cost,time(&(settingsStorage.startTime)));
	
	//adding a product to a tree
	product *temp = root;
	if(root == NULL)
	{
		root = newProduct;
	}
	else
	{
	//traversing the tree
		
		//while loop ender
		bool kill = 0;
		while(!kill)
		{
			// if the title comes earlier in the alphabet
			if(newProduct->name < temp->name)
			{
				//if there is no childe to the one compared to make the new one hte child
				if(temp->left == NULL)
				{
					//linking the nodes to eachother
					temp->left = newProduct;
					newProduct->parent = temp;
					//end the while loop
					kill = 1;
				}
				// if there is a child there move down the tree
				else
				{
					temp = temp->left;
				}
			}
			else //same execution as above on if it is greater
			{
				if(temp->right == NULL)
				{
					temp->right = newProduct;
					newProduct->parent = temp;
					kill = 1;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}

}
//stupid method that could probably be avoided but I was using time so this was easy
void market::addSettings(double decay, double decayBase, bool recency, bool max, double maxP,double postMultiplier)
{
	settingsStorage.decayRate = -1 * decay;
	settingsStorage.decayRateBase = decayBase;
	settingsStorage.recencyDetection = recency;
	settingsStorage.maxPrice = max;
	settingsStorage.maxPriceMultiplier = maxP;
	
	//reason for method
	time_t startTime;
	settingsStorage.startTime = time(&startTime);
	lastTimeCheck = startTime;
	
	settingsStorage.postBuyMultiplier = postMultiplier;
}

void market::buyProduct(std::string name)
{
	product *temp = findProduct(name);
	
	//if product found
	if(temp != NULL)
	{
		//if there is more than 0 of the selected product
		if(temp->quantity != 0)
		{
			//if the user can afford it
			if(currentUser->wallet > temp->price)
			{
				//reduced the nventory by one
				(temp->quantity)--;
				
				//pay for the product
				currentUser->wallet = currentUser->wallet - temp->price;
				//for use in storage after the price is changes
				double salePrice = temp->price;
				std::cout << "You have " << currentUser->wallet << " dollars left in your wallet." << std::endl;
				
				//don't remember exactly why this is here but the idea seems important
				if(temp->base < temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold))))
				{
					temp->price = temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold)));
				}
				
				temp->lastSold = time(&settingsStorage.startTime);
				
				//stroing the purchase information every where (very memory inefficient)
				purchase *newPurchase = new purchase(time(&settingsStorage.startTime),currentUser,temp,salePrice);
				temp->price = temp->price*(settingsStorage.postBuyMultiplier);
				std::cout << "The new price is " << temp->price << " and there are " << temp->quantity << " left" << std::endl ;
				purchaseBlockChain *newBlock = new purchaseBlockChain(newPurchase);
				personalPurchase *newPersonalPurchase = new personalPurchase(newPurchase);
				currentUser->purchases.push_back(newPersonalPurchase);
				blockChain.push_back(newBlock);
			}
			else
			{
				std::cout << "There is not enough money in your wallet" << std::endl;
			}
		}
		else
		{
			std::cout << "There are no " << name << "s left in stock" << std::endl;
		}
	}
	else
	{
		std::cout << "Product not found" << std::endl;
	}
}

void market::printProducts(product *node)
{
	product *temp = node;
//	std::cout << root->right << std::endl;
	if(temp->left != NULL)
	{
		printProducts(temp->left);
	}
	if(temp->name != "")
	{
		if(temp->base < temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold))))
		{
			temp->price = temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold)));
		}
		temp->lastSold = time(&settingsStorage.startTime);
		std::cout << "Name: "<< temp->name  << std::endl << "  Price: "<< temp->price << std::endl << "  Quantity: " << temp->quantity << std::endl; 
	}
	if(temp->right != NULL)
	{
		printProducts(temp->right);
	}
}

void market::printProductsSafe()
{
	printProducts(root);

}

product * market::findProduct(std::string name)
{
	//finding the product
	product * temp = root;
	int found = 0;
	//basic tree search
	while(!found)
	{
		if(temp->name == name)
		{
			found = 1;
		}
		else
		{
			if(temp->name > name)
			{
				if(temp->left != NULL)
				{
					temp = temp->left;
				}
				else
				{
					found = 2;
				}
			}
			else
			{
				if(temp->right != NULL)
				{
					temp = temp->right;
				}
				else
				{
					found = 2;
				}
			}
		}
	}
	if(found == 2)
	{
		temp = NULL;
	}
	return temp;
}

void market::timeStats()
{
	//printing out some user info 
	std::cout << "Current time: " << time(&settingsStorage.startTime) <<std::endl;  
	std::cout << "Last time check was  " << time(&settingsStorage.startTime) - lastTimeCheck << " seconds ago" <<std::endl;
	lastTimeCheck = time(&settingsStorage.startTime);
}

void market::addNewUser(std::string name, std::string password, double wallet)
{
	//makes a new node in the user list unused
	userInfo *newUser = new userInfo(name,password,wallet);
	if(!currentUser)
	{
		currentUser = newUser;
	}
	users.push_back(newUser);
	std::cout << "User Added" << std::endl;
}

void market::printProfit(product * node)
{
	//same basic idea as the tree print 
	product *temp = node;
	if(temp->left != NULL)
	{
		printProfit(temp->left);
	}
	if(temp->name != "")
	{
		if(temp->base < temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold))))
		{
			temp->price = temp->price * (pow(settingsStorage.decayRateBase,settingsStorage.decayRate * (time(&settingsStorage.startTime) - temp->lastSold)));
		}
		temp->lastSold = time(&settingsStorage.startTime);
		std::cout << "Name: "<< temp->name  << std::endl << "Profit: "<< temp->profit << std::endl; 
	}
	if(temp->right != NULL)
	{
		printProfit(temp->right);
	}
}
void market::totalProfit()
{
	totalProfit(blockChain);
}
void market::totalProfit(std::vector<purchaseBlockChain*> blockChain)
{	
	//runs though the purchase block chain and adds the net profit 
	int blockChainSize = blockChain.size();
	for(int blockChainIndex = 0; blockChainIndex < blockChainSize; blockChainIndex++)
	{
		//stores profit from each  product in its spot in the tree
		product *currentProduct = blockChain[blockChainIndex]->purchaseEvent->item;
		double salePrice = blockChain[blockChainIndex]->purchaseEvent->cost;
		currentProduct->profit = salePrice - currentProduct->cost;
	}
	//prints profits stored in tree
	printProfit(root);
}

void market::addMoney()
{
	//increases the money that the users has in their account
	std::cout << "How much would you like to add " << currentUser->name << "?" << std::endl;
	double money;
	std::string moneyS;
	getline(std::cin,moneyS);
	std::stringstream convertMoney(moneyS);
	convertMoney >> money;
	currentUser->wallet = currentUser->wallet + money;
}