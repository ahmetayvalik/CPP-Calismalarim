// Constructor Method
// The constructor must have the same name as the class

#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    // Constructor
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    void showDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

private: // Private access specifier
    string brand;
    string model;
    int year;
};

int main() {
    Car myCar("Opel", "Astra", 2018);

    myCar.showDetails();
}
