#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    // Private constructor to prevent instantiation
    Singleton() {
        cout << "Singleton instance created!" << endl;
    }

public:
    static Singleton* getInstance() {
        if (!instance) 
            instance = new Singleton();
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton!" << endl;
    }
};

// Initialize the static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton::getInstance()->showMessage(); // Access the singleton instance
    Singleton::getInstance()->showMessage(); // Access it again

    return 0;
}
