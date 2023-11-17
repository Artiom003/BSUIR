#pragma once
#include "Doctor.h"
#include "Patient.h"
#include <ostream>

using namespace std;
namespace Hospital_Management_System {
	class Appointment {
	private:
		string time;
		Patient* patient;
		Doctor* doctor;
	public:
		Appointment(Doctor*, Patient*, string);
		void display_info();
	};
}