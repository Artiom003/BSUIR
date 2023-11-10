#pragma once

#include "Pass_Plane.h"
#include "Cargo_Plane.h"
#include "Passenger.h"
#include "Pilot.h"
#include <vector>

namespace Airlane {
	class Flight {
	private:
		string name;
		Pass_Plane* plane = nullptr;
		Cargo_Plane* cargo_plane = nullptr;
		Pilot* pilot = nullptr;
		vector <Passenger*> passengers;
		friend class Airport;
	public:
		void add_passenger(Passenger*);
		void remove_passenger(Passenger*);
		int number_of_passengers();
		void assigh_plane(Pass_Plane*);
		void assigh_plane(Cargo_Plane*);
		void assign_pilot(Pilot*);
		void unassign_pilot(Pilot*);
		void display_info();
		Flight(string);
		~Flight();
	};
}