#include "Employees.h"
//#include "Security_Guard.h"

namespace Airlane {
	void Employees::display_number_of_employees() {
		cout << "Number of employees: " << employees.size() << endl;
	}
	void Employees::add_employee(Pilot* pilot) {
		employees.push_back(pilot->id);
	}
	void Employees::add_employee(Security_Guard* security_guard) {
		employees.push_back(security_guard->get_id());
	}
}