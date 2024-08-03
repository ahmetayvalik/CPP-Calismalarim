// Abstract Class and Pure Virtual Functions

#include <iostream>
#include <string>

class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow" << std::endl;
    }
};

int main() {
    // Animal animal; // This line would cause a compilation error because Animal is an abstract class
    Cat cat;
    cat.makeSound(); // Output: Meow
    return 0;
}
