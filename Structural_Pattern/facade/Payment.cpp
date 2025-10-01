#include "Payment.h"

void Payment::payfees(const string& student_name, double requiredfee, double paidfee) {
    if (requiredfee == paidfee) {
        cout << "[Payment] " << student_name << " paid full fees $" << paidfee << endl;
    } else {
        throw runtime_error("[Payment] Payment failed: " + student_name + 
                            " paid $" + to_string(paidfee) + 
                            " instead of $" + to_string(requiredfee));
    }
}
