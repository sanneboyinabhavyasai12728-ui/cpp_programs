#include <iostream>
using namespace std;

class Address
{
public:
    string city;

    void getAddress()
    {
        cout << "Enter city: ";
        cin >> city;
    }

    void displayAddress()
    {
        cout << "City: " << city << endl;
    }
};

class Student
{
private:
    int rollNo;
    string name;
    Address addr;   // Object of Address class as a member

public:
    void getStudent()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        addr.getAddress();
    }

    void displayStudent()
    {
        cout << "\nRoll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        addr.displayAddress();
    }
};

int main()
{
    Student s;

    s.getStudent();
    s.displayStudent();

    return 0;
}
