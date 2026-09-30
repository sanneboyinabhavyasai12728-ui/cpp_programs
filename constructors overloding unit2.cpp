#include <iostream>
using namespace std;

class Student {
    int rollNo;
    string name;

public:
    // Default constructor
    Student() {
        rollNo = 0;
        name = "Unknown";
    }

    // Parameterized constructor with one argument
    Student(int r) {
        rollNo = r;
        name = "Unknown";
    }

    // Parameterized constructor with two arguments
    Student(int r, string n) {
        rollNo = r;
        name = n;
    }

    // Display function
    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name   : " << name << endl;
    }
};

int main() {
    // Calling default constructor
    Student s1;

    // Calling one-argument constructor
    Student s2(101);

    // Calling two-argument constructor
    Student s3(102, "Rahul");

    cout << "Student 1:" << endl;
    s1.display();

    cout << "\nStudent 2:" << endl;
    s2.display();

    cout << "\nStudent 3:" << endl;
    s3.display();

    return 0;
}

