#pragma once
#include <string>
#include <iostream>
#include "Medical_Record.h"
#include "Patient.h"


using namespace std;
namespace Hospital_Management_System {
	class Doctor {
	private:
		string info;
	public:
		void check_patient(Patient*);
		string get_info();
		Doctor(string);
	};
}