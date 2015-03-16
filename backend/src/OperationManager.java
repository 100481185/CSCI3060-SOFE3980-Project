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
        this.transactions = new Transactions(transactionsFile);
        this.accounts = new Accounts(accountsFile, accountsFile); // needs to be changed to a new file path
        this.tickets = new Tickets(ticketsFile, ticketsFile); // needs to be changes to a new file path
	}

	/**
	 * This method is responsible for looping through the transaction in
	 * memory and calling the appropriate method to execute each
	 * transaction. It is also responsible for validating input and
	 * reporting a fatal error on invalid input.
	 * @return 0 on success, 1 on failure, 2 on fatal failure.
	 */
	public int processTransactions() {
		Record cur = null;
        int check = 0;
        while ((cur = this.transactions.getTransaction()) != null) {
            switch (cur.getCode()) {
                case 1:
                    if(doCreate((Regular) cur) > 0)
                        // TODO: implement error handling
                        break;
                    break;
                case 2:
                    if(doDelete((Regular) cur) > 0)
                        // TODO: implement error handling
                        break;
                    break;
                case 3:
                    if(doSell((SellBuy) cur) > 0)
                        // TODO: implement error handling
                        break;
                    break;
                case 4:
                    if(doBuy((SellBuy) cur) > 0)
                        // TODO: implement error handling
                        break;
                    break;
                case 5:
                    if(doRefund((Return) cur) > 0)
                        // TODO: implement error handling
                        break;
                    break;
                case 6:
                    if(doAddCredit((Regular) cur) > 0)
                        // TODO: implement error handling
                        break;
                    break;
                default:
                    return 2;
            }


        }
        return 0;
	}

	/**
	 * This method executes a create new user transaction on the system. It
	 * is called by doTransaction when the transaction code is 01. It
	 * proceeds to call the newUser() method in Accounts. If any errors are
	 * reported it logs them to xstream.log and outputs the error to
	 * terminal.
	 * @param regular a transaction record of type Regular
	 * @return 0 on success, 1 on failure.
	 */
	private int doCreate(Regular regular) {
		// TODO - implement OperationManager.doCreate
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for deleting a user account on the
	 * system. It is called by doTransaction when the transaction code is
	 * 02. It calls the deleteUser method from the Accounts class. If any
	 * errors are reported it logs them to xstream.log and terminal.
	 * @param record a transaction record of type Regular
	 * @return 0 on success, 1 on failure.
	 */
	private int doDelete(Regular record) {
		// TODO - implement OperationManager.doDelete
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for performing a buy tickets transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 04. It calls the buyTickets method from the Tickets class.
	 * If any errors are reported it logs them to xstream.log and terminal.
	 * @param record a transaction record of type SellBuy
	 * @return 0 on success, 1 on failure.
	 */
	private int doBuy(SellBuy record) {
		// TODO - implement OperationManager.doBuy
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for performing a sell tickets transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 03. It calls the sellTickets method from the Tickets class.
	 * If any errors are reported it logs them to xstream.log and outputs to
	 * terminal.
	 * @param record a transaction record of type SellBuy
	 * @return 0 on success, 1 on failure.
	 */
	private int doSell(SellBuy record) {
		// TODO - implement OperationManager.doSell
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for performing a refund transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 05. It calls the removeCredit and addCredit method from the
	 * Accounts class. Any errors reported are logged in xstream.log and
	 * terminal.
	 * @param record a transaction record of type Refund
	 * @return 0 on success, 1 on failure.
	 */
	private int doRefund(Return record) {
		// TODO - implement OperationManager.doRefund
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for performing a addCredit transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 06. It calls the addCredit method from the Accounts class.
	 * Any errors reported are logged in xstream.log and outputs to terminal.
	 * @param record a transaction record of type Regular
	 * @return 0 on success, 1 on failure.
	 */
	private int doAddCredit(Regular record) {
		// TODO - implement OperationManager.doAddCredit
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param argv
	 */
	public static void main(String[] argv) {
		// TODO - implement OperationManager.main
		throw new UnsupportedOperationException();
	}

}