#include <iostream>
using namespace std;

// Abstract Strategy
class Strategy {
public:
    virtual void execute() = 0;
};

// Concrete Strategy 1: Addition
class AddStrategy : public Strategy {
public:
    void execute() override {
        cout << "Performing addition!" << endl;
    }
};

// Concrete Strategy 2: Subtraction
class SubtractStrategy : public Strategy {
public:
    void execute() override {
        cout << "Performing subtraction!" << endl;
    }
};

// Context: Calculator
class Calculator {
private:
    Strategy* strategy;
public:
    void setStrategy(Strategy* newStrategy) {
        strategy = newStrategy;
    }

    void calculate() {
        strategy->execute();
    }
};

int main() {
    Calculator calc;

    // Using addition strategy
    calc.setStrategy(new AddStrategy());
    calc.calculate();

    // Using subtraction strategy
    calc.setStrategy(new SubtractStrategy());
    calc.calculate();

    return 0;
}
