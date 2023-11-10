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
		TEST_METHOD(Check_Functional)
		{
			Passenger a("Milke");
			Passenger b("Tod");
			a.get_info();
			a.set_info("Mike");
			a.check_has_ticket();
			b.display_info();
			Ticket ticket(25, 2.333);
			ticket.get_price();
			b.display_info();
			Airport bel;
			bel.display_info();
			Ticket t2(23, 899);
			t2.book_ticket(&b);
			t2.book_ticket(&a);
			Flight f("Minsk->Moscow");
			f.add_passenger(&b);

			Pilot p("Annah");
			p.set_info("Anna");
			p.get_info();
			f.unassign_pilot(&p);
			f.number_of_passengers();
			Pass_Plane s("wz-98kj");
			s.get_model();
			Cargo_Plane hd("fvygbu");
			hd.get_model();
//			bel.add_flight(&f);
			f.assigh_plane(&s);
			f.add_passenger(&b);
//			bel.add_flight(&f);
			f.assign_pilot(&p);
			bel.add_flight(&f);
			
			f.add_passenger(&a);
			t2.cancel_booking();
			bel.add_flight(&f);

			bel.display_info();
			f.remove_passenger(&b);
			Pilot l("NIk");
			Security_Guard v("hvbmnjhn");
			v.get_id();
			v.set_info("Roshan");
			v.check_passenger(&a);
			Employees w;
			w.add_employee(&p);
			w.add_employee(&v);
			w.add_employee(&l);
			w.display_number_of_employees();
			bel.add_flight(&f);
			f.display_info();
			f.assigh_plane(&s);
		}
	};
}
