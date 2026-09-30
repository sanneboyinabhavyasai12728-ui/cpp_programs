#include <iostream>
using namespace std;

// =====================================================
// 1. SINGLE INHERITANCE
// =====================================================

class Animal
{
public:
    void eat()
    {
        cout << "Animal eats food." << endl;
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << "Dog barks." << endl;
    }
};

// =====================================================
// 2. MULTIPLE INHERITANCE
// =====================================================

class Father
{
public:
    void fatherProperty()
    {
        cout << "Father's property." << endl;
    }
};

class Mother
{
public:
    void motherProperty()
    {
        cout << "Mother's property." << endl;
    }
};

class Child : public Father, public Mother
{
public:
    void childProperty()
    {
        cout << "Child's property." << endl;
    }
};

// =====================================================
// 3. MULTILEVEL INHERITANCE
// =====================================================

class Grandfather
{
public:
    void grandfather()
    {
        cout << "Grandfather class." << endl;
    }
};

class Parent : public Grandfather
{
public:
    void parent()
    {
        cout << "Parent class." << endl;
    }
};

class Son : public Parent
{
public:
    void son()
    {
        cout << "Son class." << endl;
    }
};

// =====================================================
// 4. HIERARCHICAL INHERITANCE
// =====================================================

class Vehicle
{
public:
    void vehicle()
    {
        cout << "This is a vehicle." << endl;
    }
};

class Car : public Vehicle
{
public:
    void car()
    {
        cout << "This is a car." << endl;
    }
};

class Bike : public Vehicle
{
public:
    void bike()
    {
        cout << "This is a bike." << endl;
    }
};

// =====================================================
// 5. HYBRID INHERITANCE
// =====================================================

class Person
{
public:
    void person()
    {
        cout << "This is a person." << endl;
    }
};

class Student : virtual public Person
{
public:
    void student()
    {
        cout << "This is a student." << endl;
    }
};

class Employee : virtual public Person
{
public:
    void employee()
    {
        cout << "This is an employee." << endl;
    }
};

class WorkingStudent : public Student, public Employee
{
public:
    void workingStudent()
    {
        cout << "This is a working student." << endl;
    }
};

// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    // 1. Single Inheritance
    cout << "----- SINGLE INHERITANCE -----" << endl;

    Dog d;
    d.eat();
    d.bark();

    // 2. Multiple Inheritance
    cout << "\n----- MULTIPLE INHERITANCE -----" << endl;

    Child c;
    c.fatherProperty();
    c.motherProperty();
    c.childProperty();

    // 3. Multilevel Inheritance
    cout << "\n----- MULTILEVEL INHERITANCE -----" << endl;

    Son s;
    s.grandfather();
    s.parent();
    s.son();

    // 4. Hierarchical Inheritance
    cout << "\n----- HIERARCHICAL INHERITANCE -----" << endl;

    Car car;
    car.vehicle();
    car.car();

    Bike bike;
    bike.vehicle();
    bike.bike();

    // 5. Hybrid Inheritance
    cout << "\n----- HYBRID INHERITANCE -----" << endl;

    WorkingStudent ws;
    ws.person();
    ws.student();
    ws.employee();
    ws.workingStudent();

    return 0;
}
