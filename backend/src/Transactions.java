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
		// TODO - implement Transactions.Transactions
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible retrieving a transaction record from the
	 * recordIterator by calling recordIterator.next().
	 * @return A object that represents a transaction record.
	 */
	public Record getTransaction() {
		// TODO - implement Transactions.getTransaction
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for parsing the line of text and inserting
	 * the appropriate transaction record into the transactions list
	 * @param line
	 */
	public int decode(String line) {
		// TODO - implement Transactions.decode
		throw new UnsupportedOperationException();
	}

}