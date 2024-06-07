#include <bits/stdc++.h>
using namespace std;

class Person {
public:    // access modifier
    string name;    // attributes/data member/member variables - name and age
    int age;

public:
    void setInfo(string newName, int newAge) {    // Member function to set information
        name = newName;
        age = newAge;     
    }

    void getInfo() {    // Member function to display information
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {

    Person p1;  // Creating an object of Person 
    p1.name = "Virat Kohli";    // name and age must be 'public' to access the attributes
    p1.age = 36;
    p1.getInfo();

    Person p2;
    p2.setInfo("Rohit Sharma", 37);    // use setter & getter functions
    p2.getInfo();
   

    return 0;
}