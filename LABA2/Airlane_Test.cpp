#include "pch.h"
#include "CppUnitTest.h"
#include "..//Lab2/Header.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Airlane;

namespace AirlaneTest
{
	TEST_CLASS(AirlaneConstructors)
	{
	public:		
		TEST_METHOD(Check_Initialization)
		{
			Passenger a("Mike");
			Ticket ticket(25, 2.333);
			Airport bel;
			Flight f("Minsk->Moscow");
			Pass_Plane s("wz-98kj");
			Pilot p("Anna");
			Security_Guard v("Max");
			Employees w;
			Cargo_Plane d("Bill");
		}
		TEST_METHOD(Check_Functional_Passenger_Ticket)
		{
			Passenger a("Milke");
			Passenger b("Tod");
			a.get_info();
			a.display_info();
			a.check_has_ticket();
			a.set_info("Mike");
			Ticket ticket(12, 12.3);
			ticket.book_ticket(&a);
			ticket.cancel_booking();
			ticket.book_ticket(&a);
			ticket.get_price();
		}
		TEST_METHOD(Check_Functional_Airport_Flight_Plane_Pilot_Ticket)
		{
			Passenger a("Milke");
			Passenger b("Tod");
			Ticket ticket(12, 12.3);
			ticket.book_ticket(&a);
			ticket.get_price();
			Airport bel;
			Flight fly("Maxim->loh");
			Pass_Plane plane("Holero");
			Pilot pilot("Mikes");
			pilot.get_info();
			pilot.set_info("Mike");
			fly.add_passenger(&a);
			fly.add_passenger(&b);
			fly.remove_passenger(&b);
			fly.assigh_plane(&plane);
			fly.assign_pilot(&pilot);
			fly.unassign_pilot(&pilot);
			fly.assign_pilot(&pilot);
			fly.display_info();
			fly.number_of_passengers();
			bel.add_flight(&fly);
			bel.display_info();
			bel.remove_flight(&fly);
		}
		TEST_METHOD(Plane)
		{
			Pass_Plane a("A");
			a.get_model();
			Cargo_Plane b("B");
			b.get_model();
		}
		TEST_METHOD(Check_Functional_Employees_Security_Guard_Pilot_Ticket)
		{
			Passenger a("Milke");
			Passenger b("Tod");
			Pilot p("Misha");
			p.get_info();
			Security_Guard s("Dan");
			s.get_id();
			s.get_info();
			s.set_info("Dana");
			s.check_passenger(&a);
			Employees e;
			e.add_employee(&p);
			e.add_employee(&s);
			e.display_number_of_employees();
		}
	};
}
