#include <string>
#include <sstream>
#include "price.h"
#include "item.h"

using namespace std;

Item::Item(string init_name, Price *init_price)
{
	this->name = init_name;
	this->price = init_price;
	this->quantity = 1;
}

Item::Item(const Item& other)
{
	this->name = other.name;
	this->price = other.price;
	this->quantity = other.quantity;
}

Price Item::getPrice()
{
	return *(this->price);
}

string Item::getName()
{
	return this->name;
}

unsigned int Item::getQuantity()
{
	return this->quantity;
}

void Item::incrementQuantity()
{
	++this->quantity;
}

string Item::getNameWithQuantity()
{
	stringstream ss;
	ss << name << " (" << quantity << ")";
	return ss.str();
}

