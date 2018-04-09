#include <iostream>
#include <iomanip>
#include <sstream>
#include "price.h"

using namespace std;

Price::Price()
{
	dollars = 0;
	cents = 0;
}

Price::Price(unsigned int init_dollars, unsigned int init_cents)
{
	this->dollars = init_dollars;
	this->cents = init_cents;
}

Price& Price::operator+=(const Price& rhs)
{
	// ************* TO DO *************
	// add the values in rhs to the values in this object
	this->dollars += rhs.dollars;
	this->cents += rhs.cents;

	if(this->cents >= 100)
	{
		++this->dollars;
		this->cents -= 100;
	}
	return *this;
}

string Price::toString()
{
	stringstream ss;
	// ************* TO DO *************
	// insert the data into the stringstream, formatted as follows:
	// $[dollars].[cents]
	// where cents is two spaces wide, padded with zeroes
	
	ss << setfill('0') << " $" << this->dollars << "." << setw(2) << this->cents << endl;

	return ss.str();
}
