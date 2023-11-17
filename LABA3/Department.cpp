#include "Department.h"
namespace Hospital_Management_System {
	Department::Department(string info) {
		this->info = info;
	}
	void Department::add_doctor(Doctor* doctor) {
		doctors.push_back(doctor);
	}
	void Department::add_patient(Patient* patient) {
		patients.push_back(patient);
	}
	void Department::display_list_of_doctors() {
		for (int i = 0; i < doctors.size(); i++) {
			cout << i + 1 << "." << doctors[i]->get_info() << endl;
		}
	}
	void Department::display_list_of_patients() {
		for (int i = 0; i < patients.size(); i++) {
			cout << i + 1 << "." << patients[i]->get_info() << endl;
		}
	}
}