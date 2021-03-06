#include <iostream>
#include <string>
#include "person.h"

int main()
{
    // creating a instance of a class person with default members
    Person old_man;
 
    // setting members to user defined values 
    old_man.setFirstName("Albert");
    old_man.setLastName("Einstein");
    old_man.setAge(75);
    old_man.setGender('M');
    old_man.printPerson();

    Person golfer("Tiger", "Woods", '0', 'M');
    golfer.setAge(36);
       
    cout << endl << "My favorite golfer is " 
         << golfer.getFirstName() << " "
         << golfer.getLastName() << "." << endl;

    cout << "He is " << golfer.getAge()  
         << " years old and shares his first name with our football team!" 
         << endl << endl;

    // now create pointer to a Person. 
    Person * ptr = new Person();
    ptr->setFirstName("Michael");
    ptr->setLastName("Jordan");
    cout << "Should print \"Michael Jordan\" below:" 
         << endl << ptr->getFirstName() << " "
         << ptr->getLastName() << endl << endl;

   
/********* TO DO: ADD YOUR CODE HERE WITH AN INSTANCE OF Person me with your own information ***************/
   //Add your code here:

	Person me;
	
	me.setFirstName("Greg");
	me.setLastName("Meaders");
	me.setAge(23);
	me.setGender('M');
	

	cout << "My name is " << me.getFirstName() << " " << me.getLastName() << " and I am " << me.getAge() << endl;
	


 cout << "Done!\n" << endl;

    return 0;
}


