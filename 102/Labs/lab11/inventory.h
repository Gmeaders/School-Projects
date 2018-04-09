#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>
#include "item.h"

using namespace std;

class Inventory
{
	private:
		vector<Item*> items;
		
	public:
		Inventory();
		Inventory(string filename);
		void addItem(Item *item);
		Item *getItem(int index);
		int getNumItems();
		string toString();
};

#endif
