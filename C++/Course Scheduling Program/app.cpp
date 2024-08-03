// Course Scheduling Program

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ders {
    string dersAdi;
    float dersSaati;
};

// Function to check if the entered hour is within the valid range
bool kontrol(float saat) {
    return (saat >= 0.0 && saat <= 24.0); 
}

int main() {
    vector<Ders> dersler;
    string dersAdi;
    float dersSaati; 
   
    // Loop to input 3 courses
    for (int i = 0; i < 3; ++i) {
        cout << "Enter course name: ";
        cin >> dersAdi;
        cout << "Enter course hour (0-24): ";
        cin >> dersSaati;

        // Check for valid hour input
        while (!kontrol(dersSaati)) {
            cout << "Invalid input! Please enter an hour value between (0-24): ";
            cin >> dersSaati;
        }

        // Add the course to the vector
        dersler.push_back({dersAdi, dersSaati});
    }

    // Sort the courses by hours
    sort(dersler.begin(), dersler.end(), [](const Ders &a, const Ders &b) {
        return a.dersSaati < b.dersSaati;
    });

    // Print the sorted courses
    cout << "\nOrder of Courses:\n";
    for (const auto &ders : dersler) {
        cout << ders.dersAdi << " - " << ders.dersSaati << " hours\n";
    }

    return 0;
}
