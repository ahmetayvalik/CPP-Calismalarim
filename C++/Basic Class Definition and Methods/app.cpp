// Basic Class Definition and Methods

#include <iostream>

using namespace std;

class Car { // Class definition
    string brand; // Class properties
    string model;
    int year;

public: // Public access specifier
    void accelerate() {
        cout << "The car is accelerating" << endl;
    }

    void stop() {
        cout << "The car is stopping" << endl;
    }
};

int main() {
    Car myCar; // Creating an object of Car class

    myCar.accelerate();
    myCar.stop();

    return 0;
}
