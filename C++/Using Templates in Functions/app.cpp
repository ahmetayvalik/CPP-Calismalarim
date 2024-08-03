// Using Templates in Functions

#include <iostream>

using namespace std;

template <typename T>
T add(T x, T y) {
    return x + y;
}

int main() {
    cout << add(1, 5) << endl;
    cout << add(1.5, 4.8) << endl;
}
