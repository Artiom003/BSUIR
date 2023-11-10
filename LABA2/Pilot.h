#pragma once
#include "Flight.h"
#include "Employees.h"

namespace Airlane {
    class Pilot {
    private:
        friend class Employees;
        string id;
        string info;
    public:
        string get_info();
        void set_info(string);
        Pilot(string);
        ~Pilot() {};
    };
}