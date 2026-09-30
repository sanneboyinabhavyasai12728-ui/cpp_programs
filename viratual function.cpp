#include <iostream>
using namespace std;

class Animal
{
public:
    // Virtual function
    virtual void sound()
    {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal
{
public:
    // Overriding virtual function
    void sound() override
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
public:
    // Overriding virtual function
    void sound() override
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    Animal *ptr;

    Dog d;
    Cat c;

    // Pointer points to Dog object
    ptr = &d;
    ptr->sound();

    // Pointer points to Cat object
    ptr = &c;
    ptr->sound();

    return 0;
}
