#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "price.h"

using namespace std;

class Item
{
	private:
		Price *price;
		string name;
		unsigned int quantity;
					
	public:
		Item(string init_name, Price *init_price);
		Item(const Item& other);
		string getName();
		Price getPrice();
		void incrementQuantity();
		unsigned int getQuantity();
		string getNameWithQuantity();
};

#endif

