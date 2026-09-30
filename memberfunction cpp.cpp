#include <iostream>
using namespace std;

class Number {
    int x;

public:
    // Constructor
    Number(int a = 0) {
        x = a;
    }

    // Unary operator overloading (-)
    Number operator-() {
        return Number(-x);
    }

    // Binary operator overloading (+)
    Number operator+(Number n) {
        return Number(x + n.x);
    }

    // Display function
    void display() {
        cout << x << endl;
    }
};

int main() {
    Number n1(10), n2(20), n3;

    // Unary operator
    n3 = -n1;
    cout << "Unary operator (-n1): ";
    n3.display();

    // Binary operator
    n3 = n1 + n2;
    cout << "Binary operator (n1 + n2): ";
    n3.display();

    return 0;
}

