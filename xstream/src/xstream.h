#ifndef XSTREAM_XSTREAM_H
#define XSTREAM_XSTREAM_H

// Command Constants
#define LOGIN        11
#define LOGOUT       00
#define CREATE       01
#define DELETE       02
#define SELL         03
#define BUY          04
#define REFUND       05
#define ADDCREDIT    06


// User Type Constants
#define AA "admin"
#define FS "full-standard"
#define BS "buy-standard"
#define SS "sell-standard"



// Error Messages
#define TOOMUCH         "the amount exceeds the transaction limit (MAX=$1000.00)."
#define BADCREDIT       "you do not have enough credit to complete that command."
#define ALREADYLOGGED   "you must log out to preform that task."
#define BADACCESS       "incorrect permissions."
#define NOTLOGGED       "command only available to logged in user."
#define INVALID         "Invalid command: "

bool printMsg(int powerOff);


#endif