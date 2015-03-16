/**
 * This class represents an account for a User. It is responsible
 * for storing and retrieving a single users information. Any access
 * errors are reported to caller.
 */
public class User {

	/**
	 * a char array of size two that represents a type of User
	 */
	private String name;
	/**
	 * a string that represents the type of user
	 */
	private String type;
	/**
	 * a double that represents a User's current amount of credit.
	 */
	private double credit;

	/**
	 * Constructor method of User.
	 * @param name a string that represents the name of User
	 * @param type a string that represents the type of user
	 * @param credit a double that represents a User's current amount of credit.
	 */
	public User(String name, String type, double credit) {
		// TODO - implement User.User
		throw new UnsupportedOperationException();
	}

	public String getName() {
		return this.name;
	}

	/**
	 * 
	 * @return a string that represents the type of user
	 */
	public String getType() {
		return this.type;
	}

	public double getCredit() {
		return this.credit;
	}

	/**
	 * This method is responsible for validating and a a user account
	 * from memory. It validates that name exists on the system and reports
	 * errors to caller. If all business constraints are met it deletes the
	 * user from memory.
	 * @param name a string that represents the name of User
	 * @param amount a double that represents the amount to remove from a Users
	 * account
	 * @return 0 on success, 1 on failure, 2 on InvalidNameError
	 */
	public int addCredit(String name, double amount) {
		// TODO - implement User.addCredit
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for validating and removing credit from a
	 * user account. It validates that name exists on the system and the
	 * amount to be deducted is not greater than present amount .Any errors
	 * are reported to the caller function. If all business constraints are
	 * met it removes the amount of credit from the users account.
	 * @param name a string that represents the name of User
	 * @param amount a double that represents the amount to be deducted from a users account
	 * @return 0 on success, 1 on failure, 2 on InvalidNameError, 3 on
	 * AmountToLargeError
	 */
	public int removeCredit(String name, double amount) {
		// TODO - implement User.removeCredit
		throw new UnsupportedOperationException();
	}

}