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
	 * a char array that represents the User's type.
	 */
	private char[] type;
	/**
	 * a double that represents the amount of credit a User has.
	 */
	private double credit;

	/**
	 * Constructor method for Regular class. Calls the constructor of super
	 * to set code.
	 * @param code an integer representing the transaction number.
	 * @param user
	 * @param type
	 * @param credit
	 */
	public Regular(int code, String user, char[] type, double credit) {
		// TODO - implement Regular.Regular
		throw new UnsupportedOperationException();
	}

	public String getUser() {
		return this.user;
	}

	public char[] getType() {
		return this.type;
	}

	public double getCredit() {
		return this.credit;
	}

}