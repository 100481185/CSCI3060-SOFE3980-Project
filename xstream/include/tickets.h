#ifndef XSTREAM_EVENTS_H
#define XSTREAM_EVENTS_H

#include "../include/data.h"
#include "event.h"
#include <iostream>
#include <string>
#include <map>

#define EVENTS "data/AvailableTickets.txt"

class Tickets : public Data
{
public:
    Tickets();

    Event *find_event(string event);

    int new_event(string event, string seller, int num_tic, double price);

    int write_events();


private:
    map<string, Event> tickets_;
};


#endif // XSTREAM_TICKETS_H
