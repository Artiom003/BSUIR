#include "pch.h"
#include "CppUnitTest.h"
#include "..//Lab3/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Hospital_Management_System;

namespace Hospital_Management_System_Tests
{
	TEST_CLASS(HospitalManagementSystemTests)
	{
	public:	
		TEST_METHOD(Check_Initialization)
		{
			Patient patient("Maksimkov Maksim");
			Medical_Record medical_record;
			Doctor doctor("Shatilova");
			Department department("Dyrka");
			Appointment appointment(&doctor, &patient, "18.11.2023 9:12");
			Schedule schedule(&doctor);
			Analysis analasis(&patient, "blood test");
			Laboratory laboratory("Cab 612, 5 korpus");
			Prescription prescription(&doctor, &patient, "Sredstvo ot gemoroya");
			Medication medicine;
		}
		TEST_METHOD(Check_Functional_Patient_Doctor_Department_Appointment_Medical_Record)
		{
			Patient patient("Maksimkov Maksim");
			patient.get_info();

			Medical_Record medical_record;
			patient.set_medical_record(&medical_record);

			Doctor doctor("Shatilova");
			doctor.check_patient(&patient);
			patient.check_medical_record();

			Department department("Dyrka");
			department.add_doctor(&doctor);
			department.add_patient(&patient);
			department.display_list_of_doctors();
			department.display_list_of_patients();

			Appointment appointment(&doctor, &patient, "18.11.2023 9:12");
			appointment.display_info();

		}
		TEST_METHOD(Check_Functional_Patient_Laboratory_Analysis)
		{
			Patient patient("Maksimkov Maksim");
			patient.get_info();

			Analysis analasis(&patient, "blood test");

			Laboratory laboratory("Cab 612, 5 korpus");
			laboratory.add_analysis(&analasis);
			laboratory.display_info();
		}
		TEST_METHOD(Check_Functional_Patient_Doctor_Prescription_Medication)
		{
			Patient patient("Maksimkov Maksim");
			Doctor doctor("Shatilova");

			Prescription prescription(&doctor, &patient, "Sredstvo ot gemoroya");
			prescription.display_info();

			Medication medicine;
			medicine.add_medicine("Sredstvo ot gemoroya");
			medicine.write_medicine(&prescription);
		}
	};
}
