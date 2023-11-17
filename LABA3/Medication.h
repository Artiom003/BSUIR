#pragma once
#include "Prescription.h"
namespace Hospital_Management_System {
	class Medication {
	private:
		vector <string> medicines;
	public:
		void add_medicine(string);
		bool write_medicine(Prescription*);
	};
}