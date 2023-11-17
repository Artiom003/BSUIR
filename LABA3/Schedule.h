#pragma once
#include "Doctor.h"
#include "Appointment.h"
namespace Hospital_Management_System {
	class Schedule {
	private:
		Doctor* doctor;
		vector <Appointment*> appointments;
	public:
		Schedule(Doctor*);
		void add_appointment(Appointment*);
		void display_info();
	};
}