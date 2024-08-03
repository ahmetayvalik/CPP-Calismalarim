// Type Identification with typeid

#include <iostream>
#include <typeinfo> // Required for typeid

template <typename T>
T add(T x, T y) {
    if (*typeid(x).name() == 'i') { // Check if type is int
        std::cout << "int sum: ";
    } else if (*typeid(x).name() == 'd') { // Check if type is double
        std::cout << "double sum: ";
    } else {
        std::cout << "unknown type: ";
    }
    return x + y;
}

int main() {
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.1, 2.2) << std::endl;
    return 0;
}
