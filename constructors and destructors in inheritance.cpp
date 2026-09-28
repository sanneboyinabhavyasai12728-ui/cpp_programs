#include <iostream>
using namespace std;

class Base
{
public:
    // Constructor
    Base()
    {
        cout << "Base class Constructor" << endl;
    }

    // Destructor
    ~Base()
    {
        cout << "Base class Destructor" << endl;
    }
};

class Derived : public Base
{
public:
    // Constructor
    Derived()
    {
        cout << "Derived class Constructor" << endl;
    }

    // Destructor
    ~Derived()
    {
        cout << "Derived class Destructor" << endl;
    }
};

int main()
{
    cout << "Creating object..." << endl;

    Derived obj;

    cout << "Object is going out of scope..." << endl;

    return 0;
}
