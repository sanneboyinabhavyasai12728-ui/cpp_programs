#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal eats food." << endl;
    }
};

// Derived class from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks." << endl;
    }
};

// Derived class from Dog
class Puppy : public Dog {
public:
    void play() {
        cout << "Puppy plays." << endl;
    }
};

int main() {
    Puppy p;

    // Function inherited from Animal
    p.eat();

    // Function inherited from Dog
    p.bark();

    // Function of Puppy
    p.play();

    return 0;
}

