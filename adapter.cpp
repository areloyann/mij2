#include <iostream>
using namespace std;

// OldPrinter class represents the old printer interface
class OldPrinter {
public:
    // Virtual method that prints using the old printer
    virtual void oldPrint() {
        cout << "printing with the old printer";
    }
};

// NewPrinter class represents the new printer interface
class NewPrinter {
public:
    // Method that prints using the new printer
    void newPrint() {
        cout << "printing with the new printer";
    }
};

// PrinterAdapter class adapts the NewPrinter to work with OldPrinter interface
class PrinterAdapter : public OldPrinter {
private:
    // Private member to hold the NewPrinter object
    NewPrinter* newPrinter;

public:
    // Constructor: Initializes PrinterAdapter with a NewPrinter object
    PrinterAdapter(NewPrinter* printer) {
        newPrinter = printer;  // Store the NewPrinter object
    }

    // Overridden method: Adapt the oldPrint() to call newPrint() from NewPrinter
    void oldPrint() override {
        newPrinter->newPrint();  // Call the new printer's print method
    }
};

int main() {
    // Create a NewPrinter object
    NewPrinter* newPrinter = new NewPrinter();

    // Create a PrinterAdapter object, passing the NewPrinter object to it
    OldPrinter* Adapter = new PrinterAdapter(newPrinter);

    // Call oldPrint() on the Adapter object
    // The Adapter will redirect this call to the newPrint() method of NewPrinter
    Adapter->oldPrint();  // Output: printing with the new printer

    // Clean up by deleting the NewPrinter object
    delete newPrinter;

    return 0;
}
