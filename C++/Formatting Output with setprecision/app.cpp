// Formatting Output with setprecision

#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

using namespace std;

int main() {
    double pi = 3.141592653589793;
    cout << "Pi value: " << setprecision(10) << pi << endl;
    cout << "Pi value (fixed, precision 3): " << fixed << setprecision(3) << pi << endl;
}
