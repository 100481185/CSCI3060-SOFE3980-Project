import backend.Accounts;
import backend.User;
import junit.framework.TestCase;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * AccountsTest:
 * <brief description of class>
 */
public class AccountsTest extends TestCase{

    private Accounts accounts;

    @Before
    public void setUp() {
        accounts = new Accounts("UserAccounts.txt", "UserAccounts.out");
    }

    @After
    public void tearDown() {
        accounts = null;
    }

    @Test
    public void testConstruct() {
        assertEquals(Accounts.class, accounts.getClass());
        assertEquals(User.class, accounts.getUser("User1").getClass());
    }

}
