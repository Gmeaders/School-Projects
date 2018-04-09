#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Inventory::Inventory(string filename)
{
	// ************* TO DO *************
	
	// read in the inventory from the file specified by filename
	// the file should contain three pieces of data per item,
	// formatted as follows:
	// [name] [dollars] [cents]
	// add each item to the items vector
	/*ifstream file(filename.c_str());
	string name;
	
	Item *item;
	unsigned int dollars, cents;
	if(file.is_open())
	{
		while(!file.eof())
		{
			Price *price = new Price(dollars, cents);
			Item *item = new Item(name, price);

			file >> name >> dollars >> cents;
			*price = Price(dollars, cents);
			
			this->items.push_back(item);
		}
		file.close();
	}
	file.close();
	*/
	ifstream ifs(filename.c_str());
	string name;
	unsigned int dollars, cents;
	while(ifs.good())
	{
		ifs >> name >> dollars >> cents;
		addItem(new Item(name, new Price(dollars, cents)));
	}	 
}

void Inventory::addItem(Item *item)
{
	// ************* TO DO *************
	// add the item to the items vector
	this->items.push_back(item);
	
}

Item *Inventory::getItem(int index)
{
	// ************* TO DO *************
	// return the item specified by index
	
	return this->items.at(index);
}

int Inventory::getNumItems()
{
	// ************* TO DO *************
	// return the number of items in the inventory
	return this->items.size();
}

string Inventory::toString()
{
	stringstream ss;
	for (int i = 0; i < items.size(); ++i)
	{
		ss << i << ":" << setw(10) << items[i]->getName() << setw(8) << items[i]->getPrice().toString();
	}
	return ss.str();
}
