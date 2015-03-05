#include "../include/tickets.h"

using namespace std;

Tickets::Tickets() :
        Data(EVENTS) {
    if (ReadData() == 0) {

        // create an iterator that points to each line in file
        list<string>::iterator data_ptr = data_.begin();

        // for each line in file until EOF
        for (data_ptr; data_ptr != data_.end(); data_ptr++) {

            // get attributes from line
            string event = (*data_ptr).substr(0, 19);
            string seller = (*data_ptr).substr(20, 13);
            int num_tic = stoi((*data_ptr).substr(34, 3));
            double price = stod((*data_ptr).substr(38, 6));

            // trim whitespace from event and seller name
            event.erase(name.find_last_not_of(' ') + 1);
            seller.erase(name.find_last_not_of(' ') + 1);

            // create a new user in memory
            new_event(event, seller, num_tic, price);
        }
    }
}

Event *Tickets::find_event(string event) {
    // search for event in tickets
    map<string, Event>::iterator it = tickets_.find(event);

    // if event does not exist
    if (it == tickets_.end())
        return NULL;
    else
        // return address of Event
        return &it->second;
}

int Accounts::new_event(string event, string seller, int num_tic, double price) {
    // create an event with key=event_name and value=Event
    tickets_.insert(pair<string, Event>(event, Event(event, seller, num_tic, price)));
    return 0;
}

int Tickets::write_events() {
    // clear data buffer
    data_.clear();
    // create a pointer to the start of accounts
    map<string, Event>::iterator ptr = tickets_.begin();
    for (ptr; ptr != tickets_.end(); ptr++) {
        // get the formatted string version of the account
        // pointed to by ptr and insert it into data
        data_.push_front(ptr->second.user());
    }
    WriteData();
    return 0;
}
