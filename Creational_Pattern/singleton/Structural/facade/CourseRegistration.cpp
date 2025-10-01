#include "CourseRegistration.h"

CourseRegistration::CourseRegistration() {
    courses["Computer Science"] = 100000;
    courses["Information Technology"] = 90000;
    courses["ECE"] = 90000;
    courses["EEE"] = 80000;
}

void CourseRegistration::display_courses() {
    cout << "\nAvailable Courses:\n";
    for (auto &p : courses) {
        cout << " - " << p.first << " : $" << p.second << endl;
    }
}

bool CourseRegistration::select_course(const string& student_name, const string& course, double &fee) {
    if (courses.find(course) != courses.end()) {
        cout << "[CourseRegistration] " << student_name 
             << " registered for " << course << endl;
        fee = courses[course];
        return true;
    } else {
        cout << "[CourseRegistration] Invalid course: " << course << endl;
        return false;
    }
}
