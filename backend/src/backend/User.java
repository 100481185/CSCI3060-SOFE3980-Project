package backend;

/**
 * This class represents an account for a xstreambackend.User. It is responsible
 * for storing and retrieving a single users information. Any access
 * errors are reported to caller.
 */
public class User {

	/**
	 * a char array of size two that represents a type of xstreambackend.User
	 */
	private String name;
	/**
	 * a string that represents the type of user
	 */
	private String type;
	/**
	 * a double that represents a xstreambackend.User's current amount of credit.
	 */
	private double credit;

	/**
	 * Constructor method of xstreambackend.User.
	 * @param name a string that represents the name of xstreambackend.User
	 * @param type a string that represents the type of user
	 * @param credit a double that represents a xstreambackend.User's current amount of credit.
	 */
	public User(String name, String type, double credit) {
        this.name = name;
        this.type = type;
        this.credit = credit;
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
	 * from memory. It validates that amount does not violate any business constraints
     * and deletes the user from memory.
	 * @param amount a double that represents the amount to remove from a Users
	 * account
	 * @return 0 on success, 1 on failure, 2 on MaxAmountExceededError, 3 on
     * MaxCreditLimitError
	 */
	public int addCredit(double amount) {
        if (amount < 0 || amount > 1000.00)
            return 2;
        if ((this.credit + amount) > 999999999)
            return 3;
        this.credit += amount;
        return 0;
	}

	/**
	 * This method is responsible for validating and removing credit from a
	 * user account. It validates that name exists on the system and the
	 * amount to be deducted is not greater than present amount .Any errors
	 * are reported to the caller function. If all business constraints are
	 * met it removes the amount of credit from the users account.
	 * @param amount a double that represents the amount to be deducted from a users account
	 * @return 0 on success, 1 on failure, 2 AmountExceedsCreditError
	 */
	public int removeCredit(double amount) {
        if ((this.credit - amount) < 0)
            return 2;
        this.credit -= amount;
        return 0;
	}

}