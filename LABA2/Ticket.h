#pragma once
#include "Passenger.h"

namespace Airlane {
    class Ticket {
    private:
        int number;
        double price;
        bool is_booked = false;
        Passenger* passenger = nullptr;
    public:
        Ticket(int number, double price);
        void book_ticket(Passenger*);
        void cancel_booking();
        double get_price();
    };
}