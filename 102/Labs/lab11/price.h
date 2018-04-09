#ifndef PRICE_H
#define PRICE_H

#include <string>

using namespace std;

class Price
{
	private:
		unsigned int dollars;
		unsigned int cents;
		
	public:
		Price();
		Price(unsigned int init_dollars, unsigned int init_cents);
		Price& operator+=(const Price& rhs);
		string toString();
};

#endif
