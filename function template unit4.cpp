#include <iostream>
using namespace std;

// Function Template
template <class T>
T maximum(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int a = 10, b = 20;
    float x = 12.5, y = 8.5;
    double p = 45.67, q = 56.78;

    cout << "Maximum of integers: " << maximum(a, b) << endl;
    cout << "Maximum of floats: " << maximum(x, y) << endl;
    cout << "Maximum of doubles: " << maximum(p, q) << endl;

    return 0;
}
