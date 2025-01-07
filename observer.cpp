#include <iostream>
#include <vector>
using namespace std;

// Observer interface
class Observer {
public:
    virtual void update(int state) = 0; // To be called when the state changes
};

// Subject class
class Subject {
private:
    int state;
    vector<Observer*> observers; // List of observers
public:
    void setState(int newState) {
        state = newState;
        notify(); // Notify all observers
    }

    int getState() { return state; }

    void attach(Observer* observer) {
        observers.push_back(observer); // Add observer to the list
    }

    void notify() {
        for (Observer* observer : observers)
            observer->update(state); // Notify each observer
    }
};

// Concrete Observer
class ConcreteObserver : public Observer {
private:
    string name;
public:
    ConcreteObserver(string n) : name(n) {}

    void update(int state) override {
        cout << name << " received state: " << state << endl;
    }
};

int main() {
    Subject subject;

    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    subject.attach(&observer1); // Attach observers
    subject.attach(&observer2);

    subject.setState(5); // Notify observers with state 5

    return 0;
}
