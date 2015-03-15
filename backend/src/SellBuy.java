/**
 * This class is represents a return transaction. It is responsible for providing access to all of it attributes. It inherits the
 * attribute code and the method getCode() from Record.
 */
public class SellBuy extends Record {

	/**
	 * a string that represents the name of the Event
	 */
	private String event;
	/**
	 * a string that represents the name of the User whom is the
	 * seller
	 */
	private String sellerName;
	/**
	 * an integer representing the number of tickets for sale
	 */
	private int numTickets;
	/**
	 * a double that represents the price of the ticket
	 */
	private double price;

	/**
	 * Constructor for SellBuy class. Inherits the constructor from Record
	 * and sets the attribute code.
	 * @param event a string that represents the name of the Event
	 * @param seller a string that represents the name of the User
	 * @param numTickets an integer representing the number of tickets for sale
	 * @param price a double that represents the price of a ticket
	 * @param code an integer representing the transaction number.
	 */
	public SellBuy(String event, String seller, int numTickets, double price, int code) {
		// TODO - implement SellBuy.SellBuy
		throw new UnsupportedOperationException();
	}

	public String getEvent() {
		return this.event;
	}

	public String getSellerName() {
		return this.sellerName;
	}

	public int getNumTickets() {
		return this.numTickets;
	}

	public double getPrice() {
		return this.price;
	}

}