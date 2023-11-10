#include "Ticket.h"

namespace Airlane {
    void Ticket::book_ticket(Passenger* passenger) {
        if (is_booked) {
            cout << "Ticket is already booked" << endl;
        }
        else {
            passenger->has_ticket = true;
            this->passenger = passenger;
            is_booked = true;
        }
    }
    void Ticket::cancel_booking() {
        passenger->has_ticket = false;
        this->passenger = nullptr;
        is_booked = false;
    }
    double Ticket::get_price() {
        return price;
    }
    Ticket::Ticket(int number, double price) {
        this->number = number;
        this->price = price;
    }
}