#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal eats food." << endl;
    }
};

// First derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks." << endl;
    }
};

// Second derived class
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat meows." << endl;
    }
};

int main() {
    Dog d;
    Cat c;

    // Dog inherits from Animal
    cout << "Dog:" << endl;
    d.eat();
    d.bark();

    // Cat inherits from Animal
    cout << "\nCat:" << endl;
    c.eat();
    c.meow();

    return 0;
}

