#include "Cargo_Plane.h"
#include <iostream>
using namespace std;
namespace Airlane {
	Cargo_Plane::Cargo_Plane(string model) {
		this->model = model;
	}
	void Cargo_Plane::take_Off() {
		cout << "Plane is taking off" << endl;
	}
	void Cargo_Plane::land() {
		cout << "Plane is landing" << endl;
	}
}  