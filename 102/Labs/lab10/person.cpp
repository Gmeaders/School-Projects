#include "person.h"
#include <string>
#include <iostream>

using namespace std;

// default constructor, initializes class members to the 
// initial values
Person::Person(){
    first_name = " "; 
    last_name = " "; 
    age = 0; 
    gender = 'N'; 	
}

// constructor that initialized class members
// to the ones that are passed to it in parameters
Person::Person(string fname, string lname, int age, char gdr) :
    first_name(fname), last_name(lname), age(age), gender(gdr) {

	this->first_name = fname;
	this->last_name = lname;
	this->age = age;
	this->gender = gdr;
	
}
// accessor methods, they are used to get the 
// value of private class members
string Person::getFirstName(){

	return this->first_name;
}

string Person::getLastName(){
	return this->last_name;
}

int Person::getAge(){
	return this->age;
}

char Person::getGender(){
	return this->gender;
}

// mutator methods, they are used to set/change
// the values of private class members
void Person::setFirstName(string fname){
			
	this->first_name = fname;	
}

void Person::setLastName(string lname){
	this->last_name = lname;
}

void Person::setAge(int ag){
	this->age = ag;
}

void Person::setGender(char gdr){
	this->gender = gdr;
}

// this method prints class members of Person
void Person::printPerson(void){

	cout << "First" << getFirstName() << endl;
	cout << "Last" << getLastName() << endl;
		
}

// destructor
Person::~Person(){
    cout << " --> Called object destructor" << endl;
}
