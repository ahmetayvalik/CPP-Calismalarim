// Getter and Setter Methods
// Typically used for private properties

#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;

private:
    int maxSpeed;
    int currentSpeed;

public:
    // Parameterized constructor
    Car(string b, string m, int y, int max = 250, int current = 0)
        : brand(b), model(m), year(y), maxSpeed(max), currentSpeed(current) {}

    // Default constructor
    Car()
        : brand("Opel"), model("Astra"), year(2018), maxSpeed(250), currentSpeed(0) {}

    // Accelerate function
    void accelerate() { 
        if (currentSpeed + 10 > maxSpeed) { 
            cout << "Reached maximum speed\n"; 
        } else { 
            currentSpeed += 10; 
        } 
    } 

    // Decelerate function
    void decelerate() { 
        if (currentSpeed - 10 < 0) { 
            cout << "The car is already stopped\n"; 
        } else { 
            currentSpeed -= 10; 
        } 
    }

    // Setter method for maxSpeed
    void setMaxSpeed(int ms) {
        maxSpeed = ms;
    }

    // Getter method for maxSpeed
    int getMaxSpeed() const {
        return maxSpeed;
    }

    // Function to print car details
    void printDetails() {
        cout << "Car Brand: " << brand << endl;
        cout << "Car Model: " << model << endl;
        cout << "Car Year: " << year << endl;
        cout << "Car Maximum Speed: " << maxSpeed << " km/h" << endl;
        cout << "Car Current Speed: " << currentSpeed << " km/h" << endl << endl;
    }
};

int main() {
    Car car1("Toyota", "Corolla", 2020, 180); 
    Car car2("Honda", "Civic", 2021, 200); 
    Car car3; 

    car1.accelerate(); 
    car1.accelerate(); 
    car1.decelerate(); 
    car1.decelerate(); 
    car1.decelerate(); 

    car1.printDetails(); 
    car2.printDetails(); 
    car3.printDetails(); 

    return 0;
}
