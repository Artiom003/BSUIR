#pragma once
//#include "Header.h"
#include "Plane.h"

namespace Airlane {
	class Cargo_Plane : public Plane {
	private:
		friend class Pilot; //����� � ���������� ����� ��� ��������� ��������
		void take_Off() override;
		void land() override;
	public:
		Cargo_Plane(string);
	};
}