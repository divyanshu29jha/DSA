#include <bits/stdc++.h>
using namespace std;

class Person {
private:    // access modifier
    string name;    // attributes/data member/member variables - name and age
    int age;

public:
    Person(string newName, int newAge) {    // Parameterized constructor to initialise the object (instance of class) when created
        name = newName;
        age = newAge; 
    }

    // Person(string newName, int newAge) : name(newName), age(newAge) {}   // member initializer list (: name(newName), age(newAge)) to initialize member variables.

    void displayInfo() {    // Member function to display information
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {

    // M-1)
    Person personOnStack("Narendra Modi", 74);  // Creating an object of Person on the stack 
    personOnStack.displayInfo();    // Accessing member function directly
    // No need to explicitly free memory; it's automatically managed for stack-based objects
    // cout<< personOnStack.name;  --> gives error since name is private and cannot be accessed (use public setter & getter functions)
    
    // M-2)
    Person* personPtr = new Person("John Doe", 25);     // Using new keyword for dynamic memory allocation (heap memory)
    (*personPtr).displayInfo();
    personPtr->displayInfo();   // Accessing member function using the pointer
    delete personPtr;   // Don't forget to free the allocated memory  


    return 0;
}