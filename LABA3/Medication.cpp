#include "Medication.h"
namespace Hospital_Management_System {
    void Medication::add_medicine(string name) {
        medicines.push_back(name);
    }
    bool Medication::write_medicine(Prescription* prescription) {
        for (auto it = medicines.begin(); it != medicines.end(); it++) {
            if (*it == prescription->get_info()) {
                cout << "Medicine was written" << endl;
                return true;
                break;
            }
        }
        cout << "Medicine wasn't written" << endl;
        return false;
    }
}