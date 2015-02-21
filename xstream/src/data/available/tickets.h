#ifndef XSTREAM_AVAILABLE_TICKETS_H
#define XSTREAM_AVAILABLE_TICKETS_H

#include <iostream>
#include <list>


using namespace std;

class Ticket {
	std::string event_name;
	std::string username_seller;
	int num_ticket;
	float price;
public:
	Ticket(std::string, std::string, int, float);

	void setValues(std::string, std::string, int, float);

	std::string getEvent() {
		return event_name;
	}

	std::string getSellerName() {
		return username_seller;
	}

	int getTicketNum() {
		return num_ticket;
	}

	float getPrice() {
		return price;
	}
};

string const TICKET_TXT = "AvailableTickets.txt";

static list<Ticket> tickets;
static list<Ticket>::iterator tptr;

#endif
