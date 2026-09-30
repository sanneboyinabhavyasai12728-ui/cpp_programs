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

    // Unary operator overloading (-)
    Number operator-()
    {
        Number temp;
        temp.value = -value;
        return temp;
    }

    // Binary operator overloading (+)
    Number operator+(Number n)
    {
        Number temp;
        temp.value = value + n.value;
        return temp;
    }

    // Display function
    void display()
    {
        cout << "Value = " << value << endl;
    }
};

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
