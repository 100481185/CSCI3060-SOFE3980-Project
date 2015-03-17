package backend;

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
     * an object of type xstreambackend.User which represents the xstreambackend.User who is currently logged in
     */
    private User loggedIn;

	/**
	 * Constructor for xstreambackend.OperationManager
	 * @param transactionsFile a string representing the path of the DailyTransactions file.
	 * @param accountsFile a string representing the path of the UserAccounts file.
	 * @param ticketsFile a string representing the path of the AvailableTickets file.
	 */
	public OperationManager(String transactionsFile, String accountsFile, String ticketsFile) {
        this.transactions = new Transactions(transactionsFile);
        this.accounts = new Accounts(accountsFile, accountsFile); // needs to be changed to a new file path
        this.tickets = new Tickets(ticketsFile, ticketsFile); // needs to be changes to a new file path
        // set the first sessions logged in user to null
        this.loggedIn = setLoggedIn();
	}

	/**
	 * This method is responsible for looping through the transaction in
	 * memory and calling the appropriate method to execute each
	 * transaction. It is also responsible for validating input and
	 * reporting a fatal error on invalid input.
	 * @return 0 on success, 1 on failure, 2 on fatal failure.
	 */
	public int processTransactions() {
        // initialize and empty xstreambackend.Record
		Record cur;
        while ((cur = this.transactions.getTransaction()) != null) {
            switch (cur.getCode()) {
                case 0:
                    if ((this.loggedIn = setLoggedIn()) == null)
                        return 1;
                    break;
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
     * This method is responsible for setting the sessions currently logged
     * in user.
     * @return 0 on success, 1 on failure
     */
    public User setLoggedIn() {
        String name = transactions.getLoggedInUser();
        return this.accounts.getUser(name);
    }

	/**
	 * This method executes a create new user transaction on the system. It
	 * is called by doTransaction when the transaction code is 01. It
	 * proceeds to call the newUser() method in xstreambackend.Accounts. If any errors are
	 * reported it logs them to xstream.log and outputs the error to
	 * terminal.
	 * @param regular a transaction record of type xstreambackend.Regular
	 * @return 0 on success, 1 on failure.
	 */
	private int doCreate(Regular regular) {
		if (!loggedIn.getType().equals("AA"))
            return 1;
        return this.accounts.newUser(regular.getName(), regular.getType(), regular.getCredit());
	}

	/**
	 * This method is responsible for deleting a user account on the
	 * system. It is called by doTransaction when the transaction code is
	 * 02. It calls the deleteUser method from the xstreambackend.Accounts class. If any
	 * errors are reported it logs them to xstream.log and terminal.
	 * @param record a transaction record of type xstreambackend.Regular
	 * @return 0 on success, 1 on failure.
	 */
	private int doDelete(Regular record) {
        if (!loggedIn.getType().equals("AA"))
            return 1;
        return this.accounts.deleteUser(record.getName());
	}

	/**
	 * This method is responsible for performing a buy tickets transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 04. It calls the buyTickets method from the xstreambackend.Tickets class.
	 * If any errors are reported it logs them to xstream.log and terminal.
	 * @param record a transaction record of type xstreambackend.SellBuy
	 * @return 0 on success, 1 on failure.
	 */
	private int doBuy(SellBuy record) {
        // set a tmp event to the event in memory
        Event event = this.tickets.getEvent(record.getTitle(), record.getSeller());
        // set a tmp seller to the user in memory
        User seller = this.accounts.getUser(record.getSeller());
        // set a tmp buyer to the user in memory
        User buyer = this.loggedIn;

        // calculate num of tickets purchased
        int numTicketPurchased = event.getNumTickets() - record.getNumTickets();
        // validate num of tickets purchased is less than 4
        if (numTicketPurchased > 4) {
            return 2;
        }

        // calculate total price paid
        double total = numTicketPurchased * event.getPrice();
        // validate total does not exceed buyers available credit
        if ((this.loggedIn.getCredit() - total) < 0) {
            return 3;
        }
        // validate the addition of total does not surpass the CreditMax
        if ((seller.getCredit() + total) > 999999999)
            return 4;

        // remove credit from buyer
        buyer.removeCredit(total);
        // add credit to seller
        seller.addCredit(total);
        // preform the purchase of tickets
        event.sellTickets(numTicketPurchased);

        return 0;
    }

	/**
	 * This method is responsible for performing a sell tickets transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 03. It calls the sellTickets method from the xstreambackend.Tickets class.
	 * If any errors are reported it logs them to xstream.log and outputs to
	 * terminal.
	 * @param record a transaction record of type xstreambackend.SellBuy
	 * @return 0 on success, 1 on failure.
	 */
	private int doSell(SellBuy record) {
		if (loggedIn.getType().equals("SB"))
            return 2;
        return this.tickets.newEvent(record.getTitle(), record.getSeller(), record.getNumTickets(), record.getPrice());
    }

	/**
	 * This method is responsible for performing a refund transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 05. It calls the removeCredit and addCredit method from the
	 * xstreambackend.Accounts class. Any errors reported are logged in xstream.log and
	 * terminal.
	 * @param record a transaction record of type Refund
	 * @return 0 on success, 1 on failure.
	 */
	private int doRefund(Return record) {
        // check that the sessions user is an admin
        if (!this.loggedIn.getType().equals("AA"))
            return 1;

        // create a reference to the buyer in memory
        User buyer = this.accounts.getUser(record.getBuyer());
        // validate buyer exists on the system
        if (buyer == null) {
            return 1;
        }
        // validate that buyer account will not exceed MaxAccountLimit
        if ((buyer.getCredit() + record.getRefund()) > 999999999)
            return 1;

        // create a reference to the seller in memory
        User seller = this.accounts.getUser(record.getSeller());
        // validate seller exists on the system
        if (seller == null) {
            return 1;
        }
        // check that refund does not exceed seller's available credit
        if ((seller.getCredit() - record.getRefund()) < 0)
            return 1;

        // remove funds from seller with validation
        if(seller.removeCredit(record.getRefund()) > 0)
            return 1;

        // add funds to buyer with validation
        if(buyer.addCredit(record.getRefund()) > 0)
            return 1;

        return 0;
	}

	/**
	 * This method is responsible for performing a addCredit transaction
	 * on the system. It is called by doTransaction when the transaction
	 * code is 06. It calls the addCredit method from the xstreambackend.Accounts class.
	 * Any errors reported are logged in xstream.log and outputs to terminal.
	 * @param record a transaction record of type xstreambackend.Regular
	 * @return 0 on success, 1 on failure.
	 */
	private int doAddCredit(Regular record) {
        // check that the sessions user is an admin
        if (!this.loggedIn.getType().equals("AA"))
            return 1;

        // create a reference to the user
        User user = this.accounts.getUser(record.getName());
        // validate user exists
        if (user == null)
            return 1;

        // validate that the amount of credit is within 0 to 1000
        if (record.getCredit() < 0 || record.getCredit() > 1000)
            return 1;

        // validate that when amount added the users credit is not > 999999999
        if ((record.getCredit() + user.getCredit()) > 999999999)
            return 1;

        // add the credit with validation
        if (user.addCredit(record.getCredit()) > 0)
            return 1;

        return 0;
	}

	/**
	 * xstream - backend
     *
     * This is the main program for running the backend of xstream.
     *
     * To run with specific data files, include the paths in cmd-line. The order
     * is DailyTransactions file, UserAccounts file, AvailableTickets file.
     *
     * If no files are specified then the default data files will be used
     *
	 * @param args an array of strings from the command-line which represent filenames
	 */
	public static void main(String[] args) {
        String transactionsFile = "DailyTransactions.txt";
        String userAccountsFile = "UserAccounts.txt";
        String availableTicketsFile = "AvailableTickets.txt";
        OperationManager operationManager;
        operationManager = new OperationManager(transactionsFile, userAccountsFile, availableTicketsFile);
        operationManager.processTransactions();
	}
}