/**
 * This class controls the systems memory elements and
 * performs all the transactions from the DailyTransactions
 * file. It validate each transaction and outputs new
 * UserAccounts and AvailableTickets files for the front
 * end to use the next day.
 */
public class OperationManager {

	/**
	 * Provides access to the all of the DailyTransactions in
	 * memory.
	 */
	private Transactions transactions;
	/**
	 * Provides access to all UserAccounts in memory.
	 */
	private Accounts accounts;
	/**
	 * provides access to all tickets in the systems memory.
	 */
	private Tickets tickets;

	/**
	 * Constructor for OperationManager
	 * @param transactionsFile a string representing the path of the DailyTransactions
	 * file.
	 * @param accountsFile a string representing the path of the UserAccounts file.
	 * @param ticketsFile a string representing the path of the AvailableTickets file.
	 */
	public OperationManager(String transactionsFile, String accountsFile, String ticketsFile) {
		// TODO - implement OperationManager.OperationManager
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for looping through the transaction in
	 * memory and calling the appropriate method to execute each
	 * transaction. It is also responsible for validating input and
	 * reporting a fatal error on invalid input.
	 * @return 0 on success, 1 on failure, 2 on fatal failure.
	 */
	public int processTransactions() {
		// TODO - implement OperationManager.doTransaction
		throw new UnsupportedOperationException();
	}

	/**
	 * This method executes a create new user transaction on the system. It
	 * is called by doTransaction when the transaction code is 01. It
	 * proceeds to call the newUser() method in Accounts. If any errors are
	 * reported it logs them to xstream.log and outputs the error to
	 * terminal.
	 * @param name a String that represents the name of User
	 * @param type a car array of size 2 that represents a User's type
	 * @param credit a double that represents the amount of credit a User has.
	 * @return 0 on success, 1 on failure.
	 */
	private int doCreate(String name, char[] type, double credit) {
		// TODO - implement OperationManager.doCreate
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for deleting a user account on the
	 * system. It is called by doTransaction when the transaction code is
	 * 02. It calls the deleteUser method from the Accounts class. If any
	 * errors are reported it logs them to xstream.log and terminal.
	 * @param name a String that represents the name of User
	 * @return 0 on success, 1 on failure.
	 */
	private int doDelete(String name) {
		// TODO - implement OperationManager.doDelete
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for performing a buy tickets transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 04. It calls the buyTickets method from the Tickets class.
	 * If any errors are reported it logs them to xstream.log and terminal.
	 * @param event a string that represents the name of an Event
	 * @param seller a String that represents the name of the User who is selling the tickets
	 * @param numTickets an integer that represents the quantity of tickets for sale.
	 * @param price a double that represents the price of a Ticket.
	 * @return 0 on success, 1 on failure.
	 */
	private int doBuy(String event, String seller, int numTickets, double price) {
		// TODO - implement OperationManager.doBuy
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for performing a sell tickets transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 03. It calls the sellTickets method from the Tickets class.
	 * If any errors are reported it logs them to xstream.log and outputs to
	 * terminal.
	 * @param event a string that represents the name of an Event.
	 * @param seller a string that represents the name of the User selling the tickets.
	 * @param numTickets an integer that represents the number of tickets.
	 * @param price a double that represents the price of a Ticket.
	 * @return 0 on success, 1 on failure.
	 */
	private int doSell(String event, String seller, int numTickets, double price) {
		// TODO - implement OperationManager.doSell
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for performing a refund transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 05. It calls the removeCredit and addCredit method from the
	 * Accounts class. Any errors reported are logged in xstream.log and
	 * terminal.
	 * @param buyer a string that represents the name of the buyer User.
	 * @param seller a string that represents the name of the seller User.
	 * @param amount a double that represents the amount of credit to be refunded.
	 * @return 0 on success, 1 on failure.
	 */
	private int doRefund(String buyer, String seller, double amount) {
		// TODO - implement OperationManager.doRefund
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for performing a addCredit transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 06. It calls the addCredit method from the Accounts class.
	 * Any errors reported are logged in xstream.log and outputs to terminal.
	 * @param name a string that represents the name of User
	 * @param amount a double that represents the amount of credit to be added.
	 * @return 0 on success, 1 on failure.
	 */
	private int doAddCredit(String name, double amount) {
		// TODO - implement OperationManager.doAddCredit
		throw new UnsupportedOperationException();
	}

}