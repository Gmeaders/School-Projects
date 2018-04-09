#ifndef BILLOFSALE_H
#define BILLOFSALE_H

#include <string>
#include <vector>
#include "item.h"
#include "price.h"

using namespace std;

class BillOfSale
{
	private:
		vector<Item*> items;
		Price total;
		
	public:
		void addItem(Item *item);
		string toString();
};

#endif

