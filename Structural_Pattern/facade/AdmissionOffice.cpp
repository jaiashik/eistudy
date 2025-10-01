#include "AdmissionOffice.h"
#include <exception>
#include <iostream>
using namespace std;

void AdmissionOffice::show_courses() {
    register_.display_courses();
}

void AdmissionOffice::course_selection(const string& student_name, const string& course, double paid_fee) {
    appli.fillForm(student_name);

    double requiredfee = 0.0;
    if (!register_.select_course(student_name, course, requiredfee)) {
        cout << "[AdmissionOffice] Admission failed due to invalid course\n";
        return;
    }

    try {
        amount.payfees(student_name, requiredfee, paid_fee);
        verify.doc_verify(student_name);
        cout << "[AdmissionOffice] Admission successful for " << student_name << "\n\n";
    }
    catch (const exception& e) {
        cout << e.what() << endl;
        cout << "[AdmissionOffice] Admission failed for " << student_name << "\n\n";
    }
}
