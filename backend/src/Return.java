/**
 * This class represents a return transaction record. It is
 * responsible for providing access to the return transaction
 * information. It inherits Record attributes and methods.
 */
public class Return extends Record {

	/**
	 * a string that represents the name of User who is the buyer
	 */
	private String buyer;
	/**
	 * a string that represents the name of User who is the seller
	 */
	private String seller;
	/**
	 * a double that represents the amount of the refund.
	 */
	private double refund;

	/**
	 * Constructor method for the return class
	 * @param code an integer representing the transaction number.
	 * @param buyer a string that represents the name of the User who is the buyer
	 * @param seller a string that represents the name of the User who is the seller
	 * @param refund a double that represents the amount of the refund
	 */
	public Return(int code, String buyer, String seller, double refund) {
		// TODO - implement Return.Return
		throw new UnsupportedOperationException();
	}

	public String getBuyer() {
		return this.buyer;
	}

	public String getSeller() {
		return this.seller;
	}

	public double getRefund() {
		return this.refund;
	}

}