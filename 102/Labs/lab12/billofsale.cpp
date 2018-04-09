#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "billofsale.h"
#include "item.h"

using namespace std;

void BillOfSale::addItem(Item *item)
{
	vector<Item*>::iterator found_item = find_item(item->getName());

	if(found_item == items.end())
	{	
		this->items.push_back(new Item(*item));
	}
	else
	{
		(*found_item)->incrementQuantity();
	}
	
	this->total += item->getPrice();
}

vector<Item*>::iterator BillOfSale::find_item(string name)
{
	vector<Item*>::iterator iter;
	for(iter = items.begin(); iter != items.end(); ++iter)
	{
		if((*iter)->getName() == name)
		{
			return iter;
		}
	}
	return items.end();
}	

string BillOfSale::toString()
{
	stringstream ss;
	for (vector<Item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
	{
		ss << setw(12) << (*iter)->getName() << " (" << (*iter)->getQuantity() << ")" << setw(10) << (*iter)->getPrice().toString() << endl;
	}
	ss << setfill('-') << setw(22) << "" << endl;
	ss << setfill(' ') << setw(12) << "Total" << setw(10) << total.toString() << endl;
	return ss.str();
}
