#include "Doctor.h"
namespace Hospital_Management_System {
    void Doctor::check_patient(Patient* patient) {
        srand(time(NULL));
        if (patient->medical_record == nullptr) {
            throw runtime_error("Error");
        }
        if (rand() % 3) {
            cout << "Patient: " << patient->get_info() << " with hiv!!!" << endl;
            patient->medical_record->add_treatment("hiv");

        }
        else if (rand() % 2) {
            cout << "Patient: " << patient->get_info() << " with cancer" << endl;
            patient->medical_record->add_treatment("cancer");
        }
        else {
            cout << "Patient: " << patient->get_info() << " is healthy" << endl;

        }
    }
    Doctor::Doctor(string info) {
        this->info = info;
    }
    string Doctor::get_info() {
        return info;
    }
}