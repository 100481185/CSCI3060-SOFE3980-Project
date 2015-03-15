import java.util.*;

/**
 * This class represents a AvailableTickets file, in memory. It
 * is responsible for controlling all access to ticket and event
 * information. It contains methods that add new tickets and
 * remove tickets. All accesses are validated and errors are
 * reported to caller.
 */
public class Tickets extends Data {

	/**
	 * a map with key, seller name, and value, Event, that
	 * represents the Available tickets file
	 */
	public Collection<Map<string, Event>> events;
	/**
	 * an iterator of the event map
	 */
	private Iterator<Event> eventIterator;

	/**
	 * Constructor for Tickets class. Calls super class Data to set
	 * filenames.
	 * @param readFileName a string representing the path of the existing
	 * AvailableTickets file to be read in.
	 * @param writeFilename a string representing the path of the new AvailableTickets
	 * file to be written.
	 */
	public Tickets(String readFileName, int writeFilename) {
		// TODO - implement Tickets.Tickets
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for retrieving a event from the map of
	 * event searching the events map for events that the seller has tickets
	 * for then by the event name.
	 * @param eventName a string that represents the name of the Event
	 * @param seller a string that represents the name of seller
	 * @return an object that represents a ticket for an event.
	 */
	public Event getEvent(String eventName, String seller) {
		// TODO - implement Tickets.getEvent
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for validating and executing the creation
	 * of tickets for sale. Validates that the user selling the tickets has
	 * the appropriate privileges, the number of tickets for sale does not
	 * exceed 100 and the selling price of the ticket does not exceed 999.99.
	 * @param event a string that represents the name of the Event
	 * @param seller a string that represents the name of the User who is selling
	 * the tickets
	 * @param numTickets an integer representing the number of tickets for sale
	 * @param price a double that represents the price of a ticket
	 */
	public int newEvent(String event, String seller, int numTickets, double price) {
		// TODO - implement Tickets.newEvent
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for deleting all tickets for events by a
	 * seller, from the system. It searches the map for any event with the
	 * key equal to the seller's name and deletes the event. Users with no
	 * tickets for sale will trigger a KeyNotFound error. This error needs
	 * to be caught and handled such that it does not raise and exit error.
	 * @param event
	 * @return 0 on success, 1 on failure.
	 */
	public int deleteSellerEvents(String event) {
		// TODO - implement Tickets.deleteSellerEvents
		throw new UnsupportedOperationException();
	}

	/**
	 * This method overrides the super class Data's decode. It accepts the
	 * line of text and extracts the data to create a event and insert it
	 * into the events map. The format for the data extraction is:
	 * Start (col#)
	 * Size
	 * Event: attribute
	 * 0
	 * 20
	 * title
	 * 21
	 * 15
	 * seller
	 * 37
	 * 3
	 * numTickets
	 * 41
	 * 6
	 * price
	 *  
	 * @param line
	 * @return 0 on success, 1 on failure.
	 */
	public int decode(String line) {
		// TODO - implement Tickets.decode
		throw new UnsupportedOperationException();
	}

	/**
	 * This method overrides the super class Data's encode. It is
	 * responsible for calling the next event from the eventIterator and
	 * formatting the event attributes into a string.
	 * @return a string that represents the event to be written to file
	 */
	public String encode() {
		// TODO - implement Tickets.encode
		throw new UnsupportedOperationException();
	}

}