#include "Plane.h"
#include "Passenger.h"
#include "Flight.h"

namespace Airlane {
    void Flight::add_passenger(Passenger* passenger) {
        if (passenger->check_has_ticket()) {
            passengers.push_back(passenger);
        }
        else {
            throw runtime_error("Can't add passenger because without ticket");
        }
    }
    void Flight::remove_passenger(Passenger* passenger) {
        for (auto it = passengers.begin(); it != passengers.end(); it++) {
            if (*it == passenger) {
                passengers.erase(it);
                break;
            }
        }
    }
    Flight::Flight(string name) {
        this->name = name;
    }
    int Flight::number_of_passengers() {
        return passengers.size();
    }
    void Flight::display_info() {
        if (this->plane == nullptr && this->pilot == nullptr) {
            cout << "Flight: " << name << "\nPlane: missing\nPilot: missing\nPassengers : " << number_of_passengers() << endl;
        }
        else if (this->plane == nullptr && this->pilot != nullptr) {
            cout << "Flight: " << name << "\nPlane: missing\nPilot: " << pilot->get_info() << "\nPassengers : " << number_of_passengers() << endl;
        }
        else if (this->plane != nullptr && this->pilot == nullptr) {
            cout << "Flight: " << name << "\nPlane: " << plane->get_model() << "\nPilot: missing\nPassengers : " << number_of_passengers() << endl;
        }
        else {
            cout << "Flight: " << name << "\nPlane : " << plane->get_model() << "\nPassengers : " << number_of_passengers() << endl;
        }
    }
    void Flight::assigh_plane(Pass_Plane* plane) {
        this->plane = plane;
    }
    void Flight::assigh_plane(Cargo_Plane* plane) {
        this->cargo_plane = plane;
    }
    Flight::~Flight() {
        cout << "Information of flight: " << name << " was lost" << endl;
    }
    void Flight::assign_pilot(Pilot* pilot) {
        this->pilot = pilot;
    }
    void Flight::unassign_pilot(Pilot* pilot) {
        this->pilot = nullptr;
    }
}
