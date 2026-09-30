#include <iostream>
using namespace std;

// Base class
class Person {
public:
    void displayPerson() {
        cout << "This is a person." << endl;
    }
};

// Derived class 1
class Student : virtual public Person {
public:
    void study() {
        cout << "Student studies." << endl;
    }
};

// Derived class 2
class Employee : virtual public Person {
public:
    void work() {
        cout << "Employee works." << endl;
    }
};

// Derived class inheriting from Student and Employee
class WorkingStudent : public Student, public Employee {
public:
    void manage() {
        cout << "Working student manages studies and work." << endl;
    }
};

int main() {
    WorkingStudent ws;

    ws.displayPerson();
    ws.study();
    ws.work();
    ws.manage();

    return 0;
}

