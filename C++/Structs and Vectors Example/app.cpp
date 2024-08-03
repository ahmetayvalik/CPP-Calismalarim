// Structs and Vectors Example

#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> people = {
        {"Ali", 30},
        {"Veli", 25},
        {"Hale", 35}
    };

    // Sorting and printing can be added here if needed

    return 0;
}
