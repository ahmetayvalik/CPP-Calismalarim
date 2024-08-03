// Course Management Program

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Course {
    string courseName;     // Course name
    float courseHours;     // Course hours
    string teacherName;    // Teacher name

    // Overloading operator<< for easy printing
    friend ostream& operator<<(ostream& os, const Course& course) {
        os << course.courseName << " - " << course.courseHours << " hours, Teacher: " << course.teacherName;
        return os;
    }
};

bool isValidHour(float hour) {
    return (hour >= 0.0 && hour <= 24.0);
}

int main() {
    vector<Course> courses;   // Vector to store courses
    string courseName;
    float courseHours;
    string teacherName;

    // Loop for inputting 3 courses
    for (int i = 0; i < 3; ++i) {
        cout << "Enter course name: ";
        cin >> courseName;
        cout << "Enter course hours (0-24): ";
        cin >> courseHours;

        // Ensure valid course hours input
        while (!isValidHour(courseHours)) {
            cout << "Invalid input! Please enter an hour value between (0-24): ";
            cin >> courseHours;
        }

        cout << "Enter teacher name: ";
        cin >> teacherName;

        courses.push_back({courseName, courseHours, teacherName});
    }

    // Sorting courses by course hours
    sort(courses.begin(), courses.end(), [](const Course &a, const Course &b) {
        return a.courseHours < b.courseHours;
    });

    // Printing sorted courses
    cout << "\nCourse Schedule:\n";
    for (const auto &course : courses) {
        cout << course << endl;
    }

    return 0;
}
