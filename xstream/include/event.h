#ifndef XSTREAM_EVENT_H
#define XSTREAM_EVENT_H

#include "xstream.h"
#include <iostream>
#include <sstream>
#include <list>

using namespace std;

class Event
{
public:

    Event();

    Event(string event, string seller, int num_tickets , double price);

    string eventname();

    string seller();

    int num_tickets();

    double price();

    string event() const;

    void set_event_name(string event);
    void setSeller(string seller);
    void setNumTickets(int num_tickets);
    void setPrice(double price);

private:
    string event_;
    string seller_;
    int num_tickets_;
    double price_;
};

#endif // XSTREAM_EVENT_H
