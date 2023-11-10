#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace Airlane {
    class Passenger {
    private:
        friend class Ticket;
        friend class Airport;
        bool has_ticket = false;
        string info;
        string id;
    public:
        string get_info();
        bool check_has_ticket();
        void display_info();
        void set_info(string);
        Passenger(string);
        ~Passenger() {};
    };
}