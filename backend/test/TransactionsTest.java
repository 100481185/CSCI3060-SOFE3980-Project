import backend.Transactions;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * TranasactionsTest:
 * <brief description of class>
 */
public class TransactionsTest {

    private Transactions transactions;

    @Before
    public void setUp() {
        transactions = new Transactions("DailyTransactions.txt");
    }

    @After
    public void tearDown() {
        transactions = null;
    }

    @Test
    public void testGetTransaction() throws Exception {

    }


    @Test
    public void testGetLoggedInUser() throws Exception {

    }

    @Test
    public void testDecode() throws Exception {

    }
}
