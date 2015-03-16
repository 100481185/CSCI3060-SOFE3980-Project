/**
 * This class represents a regular transaction in the
 * systems memory. It is responsible for providing access to
 * regular transaction information.
 */
public class Regular extends Record {

	/**
	 * a string that represents the name of User
	 */
	private String user;
	/**
	 * a string that represents the type of user
	 */
	private String type;
	/**
	 * a double that represents the amount of credit a User has.
	 */
	private double credit;

	/**
	 * Constructor method for Regular class. Calls the constructor of super
	 * to set code.
	 * @param code an integer representing the transaction number.
	 * @param user
	 * @param type a string that represents the type of user
	 * @param credit
	 */
	public Regular(int code, String user, String type, double credit) {
		// TODO - implement Regular.Regular
		throw new UnsupportedOperationException();
	}

	public String getUser() {
		return this.user;
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

}