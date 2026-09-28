#include <iostream>
using namespace std;

// Abstract class
class Shape
{
public:
    // Pure virtual function
    virtual void area() = 0;
};

// Derived class: Circle
class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    void area() override
    {
        cout << "Area of Circle = "
             << 3.14159 * radius * radius << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape
{
private:
    float length, breadth;

public:
    Rectangle(float l, float b)
    {
        length = l;
        breadth = b;
    }

    void area() override
    {
        cout << "Area of Rectangle = "
             << length * breadth << endl;
    }
};

// Derived class: Triangle
class Triangle : public Shape
{
private:
    float base, height;

public:
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }

    void area() override
    {
        cout << "Area of Triangle = "
             << 0.5 * base * height << endl;
    }
};

int main()
{
    Circle c(5);
    Rectangle r(10, 5);
    Triangle t(8, 6);

    // Base class pointer
    Shape *ptr;

    ptr = &c;
    ptr->area();

    ptr = &r;
    ptr->area();

    ptr = &t;
    ptr->area();

    return 0;
}
