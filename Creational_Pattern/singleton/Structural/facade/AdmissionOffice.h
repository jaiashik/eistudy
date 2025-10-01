#ifndef ADMISSIONOFFICE_H
#define ADMISSIONOFFICE_H

#include "Application.h"
#include "CourseRegistration.h"
#include "Payment.h"
#include "DocumentVerification.h"

class AdmissionOffice {
    Application appli;
    CourseRegistration register_;
    Payment amount;
    DocumentVerification verify;

public:
    void show_courses();
    void course_selection(const string& student_name, const string& course, double paid_fee);
};

#endif
