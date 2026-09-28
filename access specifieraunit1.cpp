#include <iostream>
using namespace std;

class Student {
private:
    int marks;              // Private member

protected:
    int rollNo;             // Protected member

public:
    // Constructor with default argument
    Student(int r = 101, int m = 75) {
        rollNo = r;
        marks = m;
    }

    // Function with default arguments
    void display(string name = "Student") {
        cout << "Name  : " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks : " << marks << endl;
    }
};

int main() {
    // Using default constructor arguments
    Student s1;

    // Providing values for constructor arguments
    Student s2(102, 85);

    cout << "Student 1:" << endl;
    s1.display();

    cout << "\nStudent 2:" << endl;
    s2.display("Rahul");

    return 0;
}

