#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "billofsale.h"
#include "item.h"

using namespace std;

void BillOfSale::addItem(Item *item)
{
	// ************* TO DO *************
	// add the item to the items vector
	this->items.push_back(item);
	// add the item price to the total
	this->total += item->getPrice();
}

string BillOfSale::toString()
{
	stringstream ss;
	for (vector<Item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
	{
		ss << setw(10) << (*iter)->getName() << setw(8) << (*iter)->getPrice().toString() << endl;
	}
	ss << setfill('-') << setw(18) << "" << endl;
	ss << setfill(' ') << setw(10) << "Total" << setw(8) << total.toString() << endl;
	return ss.str();
}
