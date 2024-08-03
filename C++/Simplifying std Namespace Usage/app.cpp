// Simplifying std Namespace Usage

#include <iostream>

using namespace std; // Avoids using std:: prefix repeatedly

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "You entered: " << number << endl;
}
