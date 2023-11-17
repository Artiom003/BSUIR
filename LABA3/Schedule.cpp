#include "Schedule.h"
namespace Hospital_Management_System {
	Schedule::Schedule(Doctor* doctor) {
		this->doctor = doctor;
	}
	void Schedule::add_appointment(Appointment* appointment) {
		appointments.push_back(appointment);
	}
	void Schedule::display_info() {
		for (int i = 0; i < appointments.size(); i++) {
			cout << i + 1 << ".";
			appointments[i]->display_info();
		}
	}
}