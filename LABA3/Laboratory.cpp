#include "Laboratory.h"
namespace Hospital_Management_System {
	Laboratory::Laboratory(string info) {
		this->info = info;
	}
	void Laboratory::display_info() {
		for (int i = 0; i < tests.size(); i++) {
			cout << i + 1 << ".";
			tests[i]->display_info();
		}
	}
	void Laboratory::add_analysis(Analysis* analysis) {
		tests.push_back(analysis);
	}
}