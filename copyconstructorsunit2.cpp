#include <iostream>
using namespace std;

class Student {
    int rollNo;
    string name;

public:
    // Parameterized constructor
    Student(int r, string n) {
        rollNo = r;
        name = n;
    }

    // Copy constructor
    Student(const Student &s) {
        rollNo = s.rollNo;
        name = s.name;
    }

    // Display function
    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name   : " << name << endl;
    }
};

int main() {
    // Create the first object
    Student s1(101, "Rahul");

    // Create second object using copy constructor
    Student s2 = s1;

    cout << "Original Object:" << endl;
    s1.display();

    cout << "\nCopied Object:" << endl;
    s2.display();

    return 0;
}

