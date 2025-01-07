#include <iostream>
#include <vector>
using namespace std;

// Single Responsibility Principle
// Each class should have one job.

// A class to represent a `Shape` for drawing
class Shape {
public:
    virtual void draw() const = 0; // Abstract method for drawing a shape
};

// Different shape classes implementing the abstract `Shape` class

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Square" << endl;
    }
};

// Open/Closed Principle
// We can extend the functionality of `Shape` without modifying its original code.

class ShapeDrawer {
public:
    // Can accept any shape (e.g., Circle, Square) and draw them
    void drawShape(const Shape* shape) {
        shape->draw();  // The draw method is called based on the object passed
    }
};

// Liskov Substitution Principle
// Derived classes (Circle and Square) can be used wherever the base class `Shape` is used.

void drawAnyShape(const Shape* shape) {
    shape->draw();  // You can safely use any derived class object
}

// Interface Segregation Principle
// Instead of having one large interface, we divide it into smaller interfaces.

class Printer {
public:
    virtual void print() = 0;  // The print method
};

class Scanner {
public:
    virtual void scan() = 0;  // The scan method
};

// Dependency Inversion Principle
// High-level modules should not depend on low-level modules, but both should depend on abstractions.

class MultiFunctionDevice : public Printer, public Scanner {
public:
    void print() override {
        cout << "Printing document" << endl;
    }

    void scan() override {
        cout << "Scanning document" << endl;
    }
};

int main() {
    // Using Single Responsibility and Open/Closed Principles
    ShapeDrawer shapeDrawer;
    Circle circle;
    Square square;

    shapeDrawer.drawShape(&circle); // Output: Drawing a Circle
    shapeDrawer.drawShape(&square); // Output: Drawing a Square

    // Using Liskov Substitution Principle
    drawAnyShape(&circle); // Output: Drawing a Circle
    drawAnyShape(&square); // Output: Drawing a Square

    // Using Interface Segregation Principle and Dependency Inversion Principle
    MultiFunctionDevice mfd;
    mfd.print();  // Output: Printing document
    mfd.scan();   // Output: Scanning document

    return 0;
}
