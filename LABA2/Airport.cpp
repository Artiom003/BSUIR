#include "Airport.h"

namespace Airlane {
	void Airport::display_info() {
		for (int i = 0; i < flights.size(); i++) {
			cout << i + 1 << "." << flights[i] << endl;
		}
	}
	void Airport::add_flight(Flight* flight) {
			if (flight->plane == nullptr) {
				throw runtime_error("flight without plane");
			}
			if (flight->number_of_passengers() == 0) {
				throw runtime_error("flight without passengers");
			}
			if (flight->pilot == nullptr) {
				throw runtime_error("flight without pilot");
			}
			flights.push_back(flight);
		
	}
	void Airport::remove_flight(Flight* flight) {
		for (auto it = flights.begin(); it != flights.end(); it++) {
			if (*it == flight) {
				flights.erase(it);
				break;
			}
		}
	}
}