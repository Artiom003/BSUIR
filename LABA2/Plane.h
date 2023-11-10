#pragma once
#include <string>

using namespace std;

namespace Airlane {
	class Plane {
	public:
		string get_model() {
			return model;
		}
		string model = "k";
	private:
		virtual void take_Off() = 0;
		virtual void land() = 0;
	};
}