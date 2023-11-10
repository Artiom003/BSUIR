#pragma once
#include <vector>
#include "Flight.h"

using namespace std;

namespace Airlane {
    class Airport {
    private:
        vector <Flight*> flights;
    public:
        void display_info();
        void add_flight(Flight* flight);
        void remove_flight(Flight* flight);
    };
}