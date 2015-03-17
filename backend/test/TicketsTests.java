import backend.Event;
import backend.Tickets;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

/**
 * Tickets:
 * <brief description of class>
 */
public class TicketsTests {
    private Event valid;
    private Event titleExceedsMax;
    private Event sellerNameExceedsMax;
    private Event numTicketsExeedsMax;
    private Event numTicketsAtTopLimit;
    private Event numTicketsAtBottomLimit;
    private Event priceExceedsMax;

    private boolean expt;

    private Tickets tickets;

    @Before
    public void setUp() {
        tickets = new Tickets();
        valid = new Event("ValidTicket", "User1", 5, 50.25);
        titleExceedsMax = new Event("InvalidTicketTitleExceedMax", "User1", 5, 50.25);
        sellerNameExceedsMax = new Event("InvalidSeller", "SellerNameExceedsMax", 5, 50.25);
        numTicketsExeedsMax = new Event("InvalidNumTickets", "ExceedsMax", 101, 50.25);
        numTicketsAtTopLimit = new Event("InvalidNumTickets", "ExceedsMax", 100, 50.25);
        numTicketsAtBottomLimit = new Event("InvalidNumTickets", "ExceedsMax", 0, 50.25);
        priceExceedsMax = new Event("InvalidPrice", "ExceedsMax", 3, 1000.01);
    }

    @After
    public void tearDown() throws Exception {
        tickets = null;
        valid = null;
        titleExceedsMax = null;
        sellerNameExceedsMax = null;
        numTicketsExeedsMax = null;
        numTicketsAtTopLimit = null;
        numTicketsAtBottomLimit = null;
        priceExceedsMax = null;
    }

    public int newEvent(Event event) {
        String title = event.getTitle();
        String seller = event.getSeller();
        int numTickets = event.getNumTickets();
        double price = event.getPrice();
        return tickets.newEvent(title, seller, numTickets, price);
    }

    @Test
    public void testNewEvent() throws Exception {
        // expected pass test
        assertEquals(0, newEvent(valid));
        assertEquals(0, newEvent(numTicketsAtBottomLimit));
        assertEquals(0, newEvent(numTicketsAtBottomLimit));

        // expected fail tests
        assertEquals(1, newEvent(titleExceedsMax));
        assertEquals(1, newEvent(sellerNameExceedsMax));
        assertEquals(1, newEvent(numTicketsExeedsMax));
    }

    @Test
    public void testGetEvent() throws Exception {

    }

    @Test
    public void testDeleteSellerEvents() throws Exception {

    }

    @Test
    public void testDecode() throws Exception {

    }

    @Test
    public void testEncode() throws Exception {

    }
}
