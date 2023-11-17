#pragma once
#include <string>
#include "Medical_Record.h"

using namespace std;
namespace Hospital_Management_System {
	class Medical_Record;

	class Patient {
	private:
		friend class Doctor;
		string id;
		string info;
		Medical_Record* medical_record = nullptr;
	public:
		Patient(string);
		void set_medical_record(Medical_Record*);
		void check_medical_record();
		string get_info();
	};
}