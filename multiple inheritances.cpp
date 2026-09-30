#include <iostream>
using namespace std;

// First base class
class Father {
public:
    void fatherProperty() {
        cout << "Father's property." << endl;
    }
};

// Second base class
class Mother {
public:
    void motherProperty() {
        cout << "Mother's property." << endl;
    }
};

// Derived class inheriting from two base classes
class Child : public Father, public Mother {
public:
    void childProperty() {
        cout << "Child's property." << endl;
    }
};

int main() {
    Child c;

    // Functions inherited from Father and Mother
    c.fatherProperty();
    c.motherProperty();

    // Function of Child class
    c.childProperty();

    return 0;
}

