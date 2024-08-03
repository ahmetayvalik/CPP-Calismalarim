// Sorting and Printing a Vector

#include <iostream>
#include <vector> // Required for vector
#include <algorithm> // Required for sort

using namespace std;

int main() {
    vector<int> vec = {4, 2, 1, 5, 3};
    sort(vec.begin(), vec.end()); // Sorts the vector

    cout << "Sorted vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
