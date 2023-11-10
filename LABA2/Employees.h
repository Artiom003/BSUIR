#pragma once
#include "Pilot.h"
#include "Security_Guard.h"
#include <vector>

//using namespace std;

namespace Airlane {
	class Employees {
	private:
		vector <string> employees;
	public:
		void add_employee(Security_Guard*);
		void add_employee(Pilot*);
		void display_number_of_employees();
		Employees() {};
	};
}