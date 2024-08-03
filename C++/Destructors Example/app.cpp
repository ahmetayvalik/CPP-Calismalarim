// Destructors Example

#include <iostream>
#include <string>

class Animal {
public:
    Animal() {
        std::cout << "Animal Constructor" << std::endl;
    }
    virtual ~Animal() {
        std::cout << "Animal Destructor" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat() {
        std::cout << "Cat Constructor" << std::endl;
    }
    ~Cat() override {
        std::cout << "Cat Destructor" << std::endl;
    }
};

int main() {
    std::cout << "Creating object:" << std::endl;
    Animal* animal = new Cat();
    std::cout << "Destroying object:" << std::endl;
    delete animal;
    return 0;
}
