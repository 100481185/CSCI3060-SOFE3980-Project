import backend.Accounts;
import backend.OperationManager;
import backend.Tickets;
import backend.Transactions;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

/**
 * OperationManagerTest:
 * This test class is responsible for running the input output tests on data sets
 */
public class OperationManagerTest {
    // Transaction constants
    private final String tr1Create = "01 user5           AA 999999999";
    private final String tr2Delete = "02 user5           AA 999999999";
    private final String tr3Sell = "03 event4               User1           050 050.25";
    private final String tr4Buy = "04 event3               User3           003 050.25";
    private final String tr5Return = "05 User1           User3           500.25";
    private final String tr6AddCredit = "06 User1           AA 000050.20";
    private final String tr0Logout = "00 User1           AA 999999999";

    // Accounts Constants
    private final String user1 = "user1           AA 999999999";
    private final String user2 = "user2           FS 000005000";
    private final String user3 = "user3           BS 000000100";
    private final String user4 = "user4           SS 000000000";

    // Tickets Constants
    private final String ticket1 = "event1               user1           100 000025";
    private final String ticket2 = "event2               user2           050 000.25";
    private final String ticket3 = "event3               user4           050 000.25";


    private OperationManager opManager;
    private Transactions transactions;
    private Accounts accounts;
    private Tickets tickets;

    @Before
    public void setUp() {
        this.transactions = new Transactions();
        this.accounts = new Accounts();
        this.tickets = new Tickets();
        opManager = new OperationManager(transactions, accounts, tickets);
    }

    @After
    public void tearDown() {
        transactions = null;
        accounts = null;
        tickets = null;
        opManager = null;
    }

    @Test
    public void testProcessTransactions() throws Exception {
        a

        assertEquals(0, accounts.decode(""));

    }

    @Test
    public void testSetLoggedIn() throws Exception {

    }

    @Test
    public void testMain() throws Exception {

    }
}
