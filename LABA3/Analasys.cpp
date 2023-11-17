#include "Analysis.h"
namespace Hospital_Management_System {
	Analysis::Analysis(Patient* patient, string type) {
		this->patient = patient;
		this->type = type;
	}
	void Analysis::display_info() {
		cout << "Patient: " << patient->get_info() << "\tType of analysis: " << type << endl;
	}
}