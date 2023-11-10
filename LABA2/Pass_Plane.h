#pragma once
#include "Plane.h"

namespace Airlane {
	class Pass_Plane : public Plane {
	private:
		friend class Pilot; //����� � ���������� ����� ��� ��������� ��������
		void take_Off() override;
		void land() override;
	public:
		Pass_Plane(string);
	};
}