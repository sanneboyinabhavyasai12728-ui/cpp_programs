#include <iostream>
using namespace std;

class Number {
private:
    int a, b;

public:
    // Constructor
    Number(int x, int y) {
        a = x;
        b = y;
    }

    // Declaration of friend function
    friend int sum(Number n);
};

// Friend function definition
int sum(Number n) {
    // Accessing private members
    return n.a + n.b;
}

int main() {
    Number n(10, 20);

    cout << "First number  = 10" << endl;
    cout << "Second number = 20" << endl;
    cout << "Sum = " << sum(n) << endl;

    return 0;
}

