// Object Slicing Example

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual void makeSound() const {
        cout << "Animal makes no sound" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow Meow" << endl;
    }
};

void makeSound(const Animal a) { // If we used Animal &a, it would print Meow Meow
    a.makeSound();
}

int main() {
    Cat cat;
    makeSound(cat);
    return 0;
}
