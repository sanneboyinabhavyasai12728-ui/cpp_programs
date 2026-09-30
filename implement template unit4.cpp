#include <iostream>
using namespace std;

// Class Template
template <class T>
class Calculator
{
    T a, b;

public:
    Calculator(T x, T y)
    {
        a = x;
        b = y;
    }

    T add()
    {
        return a + b;
    }

    T subtract()
    {
        return a - b;
    }

    T multiply()
    {
        return a * b;
    }

    T divide()
    {
        return a / b;
    }
};

int main()
{
    // Integer objects
    Calculator<int> c1(20, 10);

    cout << "Integer Operations:" << endl;
    cout << "Addition: " << c1.add() << endl;
    cout << "Subtraction: " << c1.subtract() << endl;
    cout << "Multiplication: " << c1.multiply() << endl;
    cout << "Division: " << c1.divide() << endl;

    // Float objects
    Calculator<float> c2(15.5, 5.0);

    cout << "\nFloat Operations:" << endl;
    cout << "Addition: " << c2.add() << endl;
    cout << "Subtraction: " << c2.subtract() << endl;
    cout << "Multiplication: " << c2.multiply() << endl;
    cout << "Division: " << c2.divide() << endl;

    return 0;
}
