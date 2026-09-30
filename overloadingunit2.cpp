#include <iostream>
using namespace std;

// Inline function
inline int square(int n) {
    return n * n;
}

// Function overloading
int add(int a, int b) {
    return a + b;
}

float add(float a, float b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    // Calling inline function
    int n = 5;
    cout << "Square of " << n << " = " << square(n) << endl;

    // Calling overloaded functions
    cout << "Sum of two integers = " << add(10, 20) << endl;
    cout << "Sum of two floats = " << add(10.5f, 20.5f) << endl;
    cout << "Sum of three integers = " << add(10, 20, 30) << endl;

    return 0;
}

