/**
 * This class represents a event that has tickets for sale in the
 * system.
 */
public class Event {

	/**
	 * a string that represents the title of the event
	 */
	private String title;
	/**
	 * a string that represents the name of seller
	 */
	private String seller;
	/**
	 * an integer representing the number of tickets for sale
	 */
	private int numTickets;
	/**
	 * a double that represents the price of one ticket
	 */
	private double price;

	/**
	 * Constructor method for the Event class
	 * @param name
	 * @param seller
	 * @param numTickets
	 * @param price
	 */
	public Event(String name, String seller, int numTickets, double price) {
		// TODO - implement Event.Event
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @return a string that represents the title of the event
	 */
	public String getTitle() {
		return this.name;
	}

	public String getSeller() {
		return this.seller;
	}

	public int getNumTickets() {
		return this.numTickets;
	}

	public double getPrice() {
		return this.price;
	}

	/**
	 * This method is responsible for removing tickets from the number of
	 * tickets for sale. If the number of tickets to be removed exceeds the
	 * number of tickets for sale, an error is reported and method exits
	 * with status 2.
	 * @param numTickets an integer representing the number of tickets purchased.
	 * @return 0 on success, 1 on failure, 2 on AmountExceedsNumTickets
	 */
	public int sellTickets(int numTickets) {
		// TODO - implement Event.sellTickets
		throw new UnsupportedOperationException();
	}

}