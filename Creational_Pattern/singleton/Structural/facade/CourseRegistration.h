#ifndef COURSEREGISTRATION_H
#define COURSEREGISTRATION_H

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class CourseRegistration {
    unordered_map<string, double> courses;
public:
    CourseRegistration();
    void display_courses();
    bool select_course(const string& student_name, const string& course, double &fee);
};

#endif
