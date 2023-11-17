#pragma once
#include "Patient.h"

using namespace std;
namespace Hospital_Management_System {
	class Analysis {
	private:
		string type;
		Patient* patient;
	public:
		Analysis(Patient*, string);
		void display_info();
	};
}