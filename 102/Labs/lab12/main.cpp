#include <iostream>
#include <string>
#include "item.h"
#include "inventory.h"
#include "billofsale.h"

int main(int argv, const char *argc[])
{
	if (argv < 2)
	{
		cout << "You must specify an inventory file to load." << endl;
		return 1;
	}
	
	Inventory *inv = new Inventory(argc[1]);
	BillOfSale *bill = new BillOfSale();
	cout << inv->toString() << endl;
	
	int input = 0;
	while (input >= 0)
	{
		cout << "Add item: ";
		
		// ************* TO DO *************
		// read in a number
		// if number is greater or equal to 0 and
		// less than the number of items in the inventory,
		// then add the corresponding item to the bill
		cin >> input;
		if(input >= 0 && input < inv->getNumItems())
		{
			bill->addItem(inv->getItem(input));
		}
		
	}
	
	cout << endl << "Receipt:" << endl;
	cout << bill->toString() << endl;
	
	return 0;
}
