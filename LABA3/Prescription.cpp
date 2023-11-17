#include "Prescription.h"
namespace Hospital_Management_System {
	Prescription::Prescription(Doctor* doctor, Patient* patient, string info) {
		this->doctor = doctor;
		this->patient = patient;
		this->info = info;
	}
	void Prescription::display_info() {
		cout << "Doctor: " << doctor->get_info() << "\tPatient: " << patient->get_info() << "\tPrescription: " << info << endl;
	}
	string Prescription::get_info() {
		return info;
	}
}