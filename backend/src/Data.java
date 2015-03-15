/**
 * This class represents a base class for handling all read and write
 * operation on a file. It provides inheriting classes safe read and
 * write methods that check and report errors. It also provides
 * subclasses with methods that can be overridden to extract data
 * from lines with their individual formatting. If two files are specified in the constructor the first file will be used for read operations and the second for write operations. If one file is specified it will be used for both read and write operations.
 */
public class Data {

	/**
	 * a string representing the path of the file to be read from
	 */
	private String readFilename;
	/**
	 * a string representing the path of the file to be written to
	 */
	private String writeFilename;

	/**
	 * Constructor method for Data class. Sets readFilename and
	 * writeFilename to the filename
	 * @param fileName a string representing the path of the UserAccounts file.
	 */
	public Data(String fileName) {
		// TODO - implement Data.Data
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for reading in the file. For each line in
	 * the file the line is extracted and given as a parameter decode. It
	 * loops through the entire file until it reaches a end of file or if it
	 * encounters a read error, in which it reports the error and exits with
	 * error code 1.
	 * @return 0 on success, 1 on failure
	 */
	protected int readData() {
		// TODO - implement Data.readData
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is responsible for writing to the file. It calls encode
	 * which provides a line of text to write to the file. It continues to
	 * call encode until EOF is received, in which it marks the file with an
	 * EOF character and closes the file. If any errors occur during a write
	 * the method reports the error, closes the file and exits with status 1.
	 * @return 0 on success, 1 on failure.
	 */
	protected int writeData() {
		// TODO - implement Data.writeData
		throw new UnsupportedOperationException();
	}

	/**
	 * Constructor method for Data class. Sets separate read and write files.
	 * @param readFilename a string representing the path of the file to be read from
	 * @param fileName a string representing the path of the file to be written to
	 */
	public Data(String readFilename, String fileName) {
		// TODO - implement Data.Data
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is intended to be overridden in inheriting classes. Each
	 * class should provide a method to parse and extract data from the line
	 * of text with their individual formatting requirements. The base class
	 * simply prints the line of text to console.
	 * @param line a string that represents a line from a file.
	 */
	public int decode(String line) {
		// TODO - implement Data.decode
		throw new UnsupportedOperationException();
	}

	/**
	 * This method is intended to be overridden in inheriting classes. It is
	 * responsible for providing a line of text to the method writeData to
	 * write to file. Each subclass should provide a line of text
	 * formatted to match attribute characteristics. This method is called
	 * repeatedly by the writeData method until an EOF is received. The
	 * base class will rewrite the data in the file to the file.
	 * IMPORTANT: EOF must be on a line by itself
	 * @return a string that represents a line of text to be written to file
	 */
	public String encode() {
		// TODO - implement Data.encode
		throw new UnsupportedOperationException();
	}

}