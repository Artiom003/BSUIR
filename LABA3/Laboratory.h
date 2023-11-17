#pragma once
#include "Analysis.h"
namespace Hospital_Management_System {
	class Laboratory {
	private:
		string info;
		vector <Analysis*> tests;
	public:
		Laboratory(string);
		void display_info();
		void add_analysis(Analysis*);
	};
}