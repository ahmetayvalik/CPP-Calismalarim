// #include <iostream>
// #include <string>

// using namespace std;

// // Base Class and Derived Class with Virtual Functions
// class Animal {
// public:
//     virtual void makeSound() {
//         cout << "This animal makes no sound" << endl;
//     }
// };

// class Cat : public Animal {
// public:
//     void makeSound() override { // Overriding to provide specific behavior for Cat
//         cout << "Meow" << endl;
//     }
// };

// class Dog : public Animal {
// public:
//     void makeSound() override {
//         cout << "Bark" << endl;
//     }
// };

// int main() {
//     Animal* animal1 = new Cat();  // Animal pointer to a Cat object
//     Animal* animal2 = new Dog();  // Animal pointer to a Dog object
//     animal1->makeSound();         // Output: Meow
//     animal2->makeSound();         // Output: Bark
//     delete animal1;               // Deleting created objects
//     delete animal2;               // Deleting created objects

//     return 0;
// }

// // Object Slicing Example
// #include <iostream>
// #include <string>

// using namespace std;

// class Animal {
// public:
//     virtual void makeSound() const {
//         cout << "Animal makes no sound" << endl;
//     }
// };

// class Cat : public Animal {
// public:
//     void makeSound() const override {
//         cout << "Meow Meow" << endl;
//     }
// };

// void makeSound(const Animal a) { // If we used Animal &a, it would print Meow Meow
//     a.makeSound();
// }

// int main() {
//     Cat cat;
//     makeSound(cat);
//     return 0;
// }

// // Diamond Problem Solution with Virtual Inheritance
// #include <iostream>
// #include <string>
// using namespace std;

// class Person {
// public:
//     std::string name;
//     int age;

//     Person(const std::string &n, int a) : name(n), age(a) {}
//     virtual void greet() const {
//         std::cout << "Hello, I am " << name << std::endl;
//     }
// };

// class Student : virtual public Person {
// public:
//     Student(const std::string &n, int a) : Person(n, a) {}
// };

// class Teacher : virtual public Person {
// public:
//     Teacher(const std::string &n, int a) : Person(n, a) {}
// };

// class Assistant : public Student, public Teacher {
// public:
//     Assistant(const std::string &n, int a) : Person(n, a), Student(n, a), Teacher(n, a) {}

//     void greet() const override {
//         cout << "Hello, I am assistant " << name << endl;
//     }
// };

// int main() {
//     Assistant assistant("Elif", 24);
//     assistant.greet();
//     return 0;
// }

// // Destructors Example
// #include <iostream>
// #include <string>

// class Animal {
// public:
//     Animal() {
//         std::cout << "Animal Constructor" << std::endl;
//     }
//     virtual ~Animal() {
//         std::cout << "Animal Destructor" << std::endl;
//     }
// };

// class Cat : public Animal {
// public:
//     Cat() {
//         std::cout << "Cat Constructor" << std::endl;
//     }
//     ~Cat() override {
//         std::cout << "Cat Destructor" << std::endl;
//     }
// };

// int main() {
//     std::cout << "Creating object:" << std::endl;
//     Animal* animal = new Cat();
//     std::cout << "Destroying object:" << std::endl;
//     delete animal;
//     return 0;
// }

// // Abstract Class and Pure Virtual Functions
// #include <iostream>
// #include <string>

// class Animal {
// public:
//     virtual void makeSound() const = 0; // Pure virtual function
// };

// class Cat : public Animal {
// public:
//     void makeSound() const override {
//         std::cout << "Meow" << std::endl;
//     }
// };

// int main() {
//     // Animal animal; // This line would cause a compilation error because Animal is an abstract class
//     Cat cat;
//     cat.makeSound(); // Output: Meow
//     return 0;
// }
