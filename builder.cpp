#include <iostream>
using namespace std;

// Product: Car class
class Car {
public:
    string engine;
    string wheels;
    string color;

    void show() {
        cout << "Car with " << engine << " engine, " << wheels << " wheels, and color: " << color << endl;
    }
};

// Builder: Abstract builder class
class CarBuilder {
public:
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual void buildColor() = 0;
    virtual Car* getResult() = 0;
};

// Concrete Builder: SportsCarBuilder
class SportsCarBuilder : public CarBuilder {
private:
    Car* car;

public:
    SportsCarBuilder() {
        car = new Car();
    }

    void buildEngine() override {
        car->engine = "V8";
    }

    void buildWheels() override {
        car->wheels = "Sporty wheels";
    }

    void buildColor() override {
        car->color = "Red";
    }

    Car* getResult() override {
        return car;
    }
};

// Client code
int main() {
    // Create builder and director
    CarBuilder* builder = new SportsCarBuilder();

    // Construct the car
    builder->buildEngine();
    builder->buildWheels();
    builder->buildColor();

    // Get the car and display it
    Car* car = builder->getResult();
    car->show();

    delete builder;
    delete car;

    return 0;
}
