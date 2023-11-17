#pragma once
#include "Doctor.h"
#include "Patient.h"
namespace Hospital_Management_System {
	class Prescription {
	private:
		string info;
		Patient* patient;
		Doctor* doctor;
	public:
		Prescription(Doctor*, Patient*, string);
		void display_info();
		string get_info();
	};
}