#include <string>
#include "price.h"
#include "item.h"

using namespace std;

Item::Item(string init_name, Price *init_price)
{
	this->name = init_name;
	this->price = init_price;
}

Price Item::getPrice()
{
	return *(this->price);
}

string Item::getName()
{
	return this->name;
}

