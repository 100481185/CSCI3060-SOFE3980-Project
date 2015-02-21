#include "tickets.h"

using namespace std;

Ticket::Ticket(std::string event_name, std::string username_seller, int num_ticket, float price) {
	setValues(event_name, username_seller, num_ticket, price);
}

void Ticket::setValues(std::string Event_name, std::string username_Seller, int num_Ticket, float Price) {
	event_name = Event_name;
	username_seller = username_Seller;
	num_ticket = num_Ticket;
	price = Price;
}
