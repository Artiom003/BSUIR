#pragma once
#include <string>
#include <vector>
#include "Doctor.h"
#include "Patient.h"

using namespace std;
namespace Hospital_Management_System {
	class Department {
	private:
		string info;
		vector <Doctor*> doctors;
		vector <Patient*> patients;
	public:
		Department(string);
		void add_doctor(Doctor*);
		void add_patient(Patient*);
		void display_list_of_doctors();
		void display_list_of_patients();
	};
}