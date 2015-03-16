import java.util.Iterator;
import java.util.List;

public class Transactions extends Data {

	/**
	 * An array that represents all the transaction records in the
	 * DailyTransactions file.
	 */
	private List<Record> records;
	/**
	 * an iterator that represents the list of records.
	 */
	private Iterator<Record> recordIterator;

	/**
	 * Constructor for Transactions class. Reads in all transactions from
	 * DailyTransactions file and stores it in memory.
	 * @param fileName A string that represents the path to the DailyTransactions file.
	 */
	public Transactions(String fileName) {
        super(fileName);
        readData();
        this.recordIterator = records.iterator();
	}

	/**
	 * This method is responsible retrieving a transaction record from the
	 * recordIterator by calling recordIterator.next().
	 * @return A object that represents a transaction record, null on end of list
	 */
	public Record getTransaction() {
        // initialize a tmp record
        Record tmp = null;
        if (recordIterator.hasNext())
            tmp = recordIterator.next();
        return tmp;
	}

	/**
	 * This method is responsible for parsing the line of text and inserting
	 * the appropriate transaction record into the transactions list
	 * @param line a string that represents a a line of a file
     * @return 0 on success, 1 on failure, 2 on InvalidCodeError
	 */
	public int decode(String line) {
        // initialize a temp record
        Record tmp = null;
        // extract the code from the line
        int code = new Integer(line.substring(0, 1));

        if (code == 1 || code == 2 || code == 6) { // if tr code is Create, Delete or addCredit
            // extract name of user
            String name = line.substring(3, 17);
            // extract type of user
            String type = line.substring(19, 20);
            // extract users credit
            double credit = new Double(line.substring(22, 27));
            // create a new Regular Transaction
            tmp = new Regular(code, name, type, credit);
        } else if (code == 3 || code == 4) {   // if tr code is Buy or Sell
            // extract event title
            String title = line.substring(3, 22);
            // extract seller's name
            String seller = line.substring(24, 39);
            // extract the number of tickets for sale
            int numTickets = new Integer(line.substring(41, 43));
            // extract the price of the ticket
            double price = new Double(line.substring(45, 50));
            // create a new SellBuy transaction
            tmp = new SellBuy(code, title, seller, numTickets, price);

        } else if (code == 5) {
            // extract the buyers name
            String buyer = line.substring(3, 17);
            // extract the sellers name
            String seller = line.substring(19, 33);
            // extract the refund amount
            double refund = new Double(line.substring(35, 43));
            // create a new Return transaction
            tmp = new Return(code, buyer, seller, refund);
        } else { // Invalid Code error
            return 2;
        }

        try {

            // add transaction to memory
            this.records.add(tmp);

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

        // If add successful
        return 0;
	}

}