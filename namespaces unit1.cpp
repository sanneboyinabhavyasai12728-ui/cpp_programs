#include <iostream>
using namespace std;

// Global variable
int x = 10;

// Namespace 1
namespace First {
    int x = 20;

    void display() {
        cout << "Value of x in First namespace: " << x << endl;
    }
}

// Namespace 2
namespace Second {
    int x = 30;

    void display() {
        cout << "Value of x in Second namespace: " << x << endl;
    }
}

int main() {
    // Scope resolution operator to access global variable
    cout << "Global value of x: " << ::x << endl;

    // Accessing namespace members using scope resolution
    cout << "First namespace value: " << First::x << endl;
    cout << "Second namespace value: " << Second::x << endl;

    First::display();
    Second::display();

    return 0;
}

