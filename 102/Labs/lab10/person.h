#include <iostream>
#include <string>

using namespace std;
//same as: using std::string;

class Person{
public:
    // default constructor
    Person(); 

    // constructor
    Person(string, string, int, char);	

    // accessor methods
    string getFirstName();
    string getLastName();
    int getAge();
    char getGender(); 

    // mutator methods
    void setFirstName(string);
    void setLastName(string);
    void setAge(int);
    void setGender(char);

    void printPerson(void); 

    // destructor
    ~Person();

private:
    string first_name;
    string last_name;
    int age;
    char gender;
};
