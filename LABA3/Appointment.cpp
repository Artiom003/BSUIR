#include "Appointment.h"
namespace Hospital_Management_System {
	Appointment::Appointment(Doctor* doctor, Patient* patient, string time) {
		this->doctor = doctor;
		this->patient = patient;
		this->time = time;
	}
	void Appointment::display_info() {
		cout << "Doctor: " << doctor->get_info() << "\tPatient: " << patient->get_info() << "\tTime: " << time << endl;
	}
}