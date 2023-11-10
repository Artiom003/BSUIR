#pragma once
#include "Passenger.h"

namespace Airlane {
    class Security_Guard {
    private:
        string id;
        string info;
    public:
        bool check_passenger(Passenger* passenger);
        string get_id();
        string get_info();
        void set_info(string info);
        Security_Guard(string);
        ~Security_Guard() {};
    };
}
