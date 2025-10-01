#include "AdmissionOffice.h"

int main() {
    AdmissionOffice a;
    a.show_courses();

    a.course_selection("Alice", "Computer Science", 100000);
    a.course_selection("Bob", "EEE", 20000);
    a.course_selection("Charlie", "Medicine", 20000);

    return 0;
}
