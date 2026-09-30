#include <iostream>
using namespace std;

class Number
{
    int value;

public:
    // Constructor
    Number(int v = 0)
    {
        value = v;
    }

    // Friend function for unary operator
    friend Number operator-(Number n);

    // Friend function for binary operator
    friend Number operator+(Number n1, Number n2);

    // Display function
    void display()
    {
        cout << "Value = " << value << endl;
    }
};

// Unary operator overloading using friend function
Number operator-(Number n)
{
    Number temp;
    temp.value = -n.value;
    return temp;
}

// Binary operator overloading using friend function
Number operator+(Number n1, Number n2)
{
    Number temp;
    temp.value = n1.value + n2.value;
    return temp;
}

int main()
{
    Number n1(10), n2(20), n3;

    // Unary operator
    cout << "Unary Operator (-):" << endl;
    n3 = -n1;
    n3.display();

    // Binary operator
    cout << "\nBinary Operator (+):" << endl;
    n3 = n1 + n2;
    n3.display();

    return 0;
}
