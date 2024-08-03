// Input and Output with cin and cout

#include <iostream>
int main() {
    int number;
    std::cout << "Please enter a number: ";
    std::cin >> number;
    std::cout << "You entered: " << number << std::endl;
    return 0;
}