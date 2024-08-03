// Array Element Search with Dynamic Memory Allocation

#include <iostream>

using namespace std;

int main() {
    int elementCount;

    cout << "Enter the number of elements in the array: ";
    cin >> elementCount;

    int* array = new int[elementCount];

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < elementCount; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> array[i];
    }

    int target;

    cout << "Enter the value to search for: ";
    cin >> target;

    int foundIndex = -1; 
    for (int i = 0; i < elementCount; ++i) {
        if (array[i] == target) {
            foundIndex = i; 
            break;
        }
    }

    switch (foundIndex) {
        case -1:
            cout << "The value was not found in the array." << endl;
            break;
        default:
            cout << "The value " << target << " was found at position " << foundIndex + 1 << " in the array." << endl;
            break;
    }

    delete[] array;

    return 0;
}
