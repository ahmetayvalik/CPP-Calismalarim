// Diamond Problem Solution with Virtual Inheritance

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    std::string name;
    int age;

    Person(const std::string &n, int a) : name(n), age(a) {}
    virtual void greet() const {
        std::cout << "Hello, I am " << name << std::endl;
    }
};

class Student : virtual public Person {
public:
    Student(const std::string &n, int a) : Person(n, a) {}
};

class Teacher : virtual public Person {
public:
    Teacher(const std::string &n, int a) : Person(n, a) {}
};

class Assistant : public Student, public Teacher {
public:
    Assistant(const std::string &n, int a) : Person(n, a), Student(n, a), Teacher(n, a) {}

    void greet() const override {
        cout << "Hello, I am assistant " << name << endl;
    }
};

int main() {
    Assistant assistant("Elif", 24);
    assistant.greet();
    return 0;
}
