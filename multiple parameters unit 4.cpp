#include <iostream>
using namespace std;

// Class Template with Multiple Parameters
template <class T1, class T2>
class Example
{
    T1 value1;
    T2 value2;

public:
    Example(T1 a, T2 b)
    {
        value1 = a;
        value2 = b;
    }

    void display()
    {
        cout << "Value 1: " << value1 << endl;
        cout << "Value 2: " << value2 << endl;
    }

    void add()
    {
        cout << "Addition: " << value1 + value2 << endl;
    }
};

int main()
{
    // Object with int and float
    Example<int, float> obj1(10, 20.5);

    cout << "Integer and Float:" << endl;
    obj1.display();
    obj1.add();

    cout << endl;

    // Object with float and double
    Example<float, double> obj2(15.5, 25.75);

    cout << "Float and Double:" << endl;
    obj2.display();
    obj2.add();

    return 0;
}
