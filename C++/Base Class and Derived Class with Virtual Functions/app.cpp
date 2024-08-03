// Base Class and Derived Class with Virtual Functions

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "This animal makes no sound" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override { // Overriding to provide specific behavior for Cat
        cout << "Meow" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Bark" << endl;
    }
};

int main() {
    Animal* animal1 = new Cat();  // Animal pointer to a Cat object
    Animal* animal2 = new Dog();  // Animal pointer to a Dog object
    animal1->makeSound();         // Output: Meow
    animal2->makeSound();         // Output: Bark
    delete animal1;               // Deleting created objects
    delete animal2;               // Deleting created objects

    return 0;
}
