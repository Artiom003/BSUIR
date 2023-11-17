#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
namespace Hospital_Management_System {
	class Medical_Record {
	private:
		string id;
		vector <string> list_of_treatments;
		string treatment;
	public:
		Medical_Record();
		void display_info();
		void add_treatment(string);
	};
}