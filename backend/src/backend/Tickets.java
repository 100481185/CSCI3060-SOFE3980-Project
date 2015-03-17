package backend;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * This class represents a AvailableTickets file, in memory. It
 * is responsible for controlling all access to ticket and event
 * information. It contains methods that add new tickets and
 * remove tickets. All accesses are validated and errors are
 * reported to caller.
 */
public class Tickets extends Data {

	/**
	 * a list of Events that represents the AvailableTickets file
	 */
	public List<Event> events;
	/**
	 * an iterator of the event list
	 */
	private Iterator<Event> eventIterator;
    /**
     * a boolean that represents if the Iterator needs to be reset
     * should only be called once in encode.
     */
    private boolean reset;

    /**
     * default Constructor for Tickets class.
     * Primarily used for testing purposes
     */
    public Tickets() {
        super("AvailableTickets.txt");
        this.events = new LinkedList<Event>();
        this.eventIterator = this.events.iterator();
        this.reset = true;
    }

    /**
     * Constructor for xstreambackend.Tickets class. Calls super class xstreambackend.Data to set
	 * filenames.
     * @param readFileName a string representing the path of the existing
     * AvailableTickets file to be read in.
     * @param writeFilename a string representing the path of the new AvailableTickets
     */
	public Tickets(String readFileName, String writeFilename) {
        super(readFileName, writeFilename);
        this.events = new LinkedList<Event>();
        readData();
        this.eventIterator = this.events.iterator();
        this.reset = true;
    }

	/**
	 * This method is responsible for retrieving a event from the map of
	 * event searching the events map for events that the seller has tickets
	 * for then by the event name.
	 * @param title a string that represents the name of the xstreambackend.Event
	 * @param seller a string that represents the name of seller
	 * @return an object that represents a ticket for an event.
	 */
	public Event getEvent(String title, String seller) {
        Iterator<Event> tmpIterator = this.events.iterator();
        Event tmp = null;
        while (tmpIterator.hasNext()) {
            tmp = tmpIterator.next();
            if ( (tmp.getTitle()).equals(title) && (tmp.getSeller()).equals(seller))
                return tmp;
        }
        return null;
	}

	/**
	 * This method is responsible for validating and executing the creation
	 * of tickets for sale. Validates that the number of tickets for sale does
     * not exceed 100 and the selling price of the ticket does not exceed 999.99.
	 * @param title a string that represents the name of the xstreambackend.Event
	 * @param seller a string that represents the name of the xstreambackend.User who is selling
	 * the tickets
	 * @param numTickets an integer representing the number of tickets for sale
	 * @param price a double that represents the price of a ticket
     * @return 0 on success, 1 on failure, 2 on InvalidNumTicketsError, 3 on
     * InvalidPriceError
	 */
	public int newEvent(String title, String seller, int numTickets, double price) {
        if (title.length() > 20)
            return 1;
        if (seller.length() > 15)
            return 1;
        if (numTickets < 0 || numTickets > 100)
            return 1;
        if (price < 0 || price > 999.99)
            return 1;

        Event tmp = new Event(title, seller, numTickets, price);

        try {

            this.events.add(tmp);

        } catch (UnsupportedOperationException e){
            e.printStackTrace(System.err);
            return 1;
        } catch (ClassCastException e) {
            e.printStackTrace(System.err);
            return 1;
        } catch (NullPointerException e) {
            e.printStackTrace(System.err);
            return 1;
        } catch (IllegalArgumentException e) {
            e.printStackTrace(System.err);
            return 1;
        }
        return 0;
	}

	/**
	 * This method is responsible for deleting all tickets for events by a
	 * seller, from the system. It searches the list for an event with the
	 * seller equal to the seller's name and deletes the event. Users with no
	 * tickets for sale will trigger a KeyNotFound error. This error needs
	 * to be caught and handled such that it does not raise and exit error.
	 * @param seller a string that represents the name of the seller
	 * @return 0 on success, 1 on failure.
	 */
	public int deleteSellerEvents(String seller) {
        Iterator<Event> tmpIterator = this.events.iterator();
        Event tmp = null;
        while(tmpIterator.hasNext()) {
            tmp = tmpIterator.next();
            if (tmp.getSeller().equals(seller))

                try {

                    this.events.remove(tmp);

                } catch (UnsupportedOperationException e){
                    e.printStackTrace(System.err);
                    return 1;
                } catch (ClassCastException e) {
                    e.printStackTrace(System.err);
                    return 1;
                } catch (NullPointerException e) {
                    e.printStackTrace(System.err);
                    return 1;
                } catch (IllegalArgumentException e) {
                    e.printStackTrace(System.err);
                    return 1;
                }
        }
        return 0;
	}

	/**
	 * This method overrides the super class xstreambackend.Data's decode. It accepts the
	 * line of text and extracts the data to create a event and insert it
	 * into the events map. The format for the data extraction is:
	 * Start(col#)     Size     xstreambackend.Event: attribute
	 *      0           20          title
     *     21           15          seller
	 *     37            3          numTickets
	 *     41            6          price
	 *  
	 * @param line a string the represents a line of text from a file
	 * @return 0 on success, 1 on failure.
	 */
	public int decode(String line) {
        String title = line.substring(0, 19).trim();
        String seller = line.substring(20, 35).trim();
        int numTickets = new Integer(line.substring(36, 39));
        double price = new Double(line.substring(40));
        return newEvent(title, seller, numTickets, price);
	}

	/**
	 * This method overrides the super class xstreambackend.Data's encode. It is
	 * responsible for calling the next event from the eventIterator and
	 * formatting the event attributes into a string.
	 * @return a string that represents the event to be written to file
	 */
	public String encode() {
        if (this.reset) {
            this.eventIterator = this.events.iterator();
            this.reset = false;
        }
        String line = null;
        if (this.eventIterator.hasNext()) {
            Event tmp = this.eventIterator.next();
            line = String.format("%-20s %-15s %-03d %-06.2f", tmp.getTitle(), tmp.getSeller(), tmp.getNumTickets(), tmp.getPrice());
        }
        return line;
	}
}