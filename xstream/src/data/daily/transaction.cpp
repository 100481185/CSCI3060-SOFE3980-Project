
#include <iostream>
#include <fstream>
#include "transaction.h"

string line;

//for logout, create, delete and addcredit transaction
int Write_Regular(string code, string username, string type_, float credit){
	ofstream file;
	file.open(TRANSACTION);

	if (!file.is_open()) return -1;

	//add code and username_
	line = code + " " + username;
	if (username.length() < 15){
		for (int i = 0; i < (15 - username.length()); i++){
			line = line + " ";
		}
	}

	//add account type
	line = line + type_ + " ";

	//add credit
	if (std::to_string(credit).length() < 9){
		for (int i = 0; i < (9 - std::to_string(credit).length()); i++){
			line = line + "0";
		}
	}
	line = line + std::to_string(credit);

	//write to file
	file << line << endl;
	file.close();
	return 0;
}

//for refund transaction
int Write_Refund(string code, string username_buyer, string username_seller, float credit_refund){
	ofstream file;
	file.open(TRANSACTION);

	if (!file.is_open()) return -1;

	//add code and buyer's username_
	line = code + " " + username_buyer;
	if (username_buyer.length() < 15){
		for (int i = 0; i < (15 - username_buyer.length()); i++){
			line = line + " ";
		}
	}

	//add seller's username_
	line = code + " " + username_seller;
	if (username_seller.length() < 15){
		for (int i = 0; i < (15 - username_seller.length()); i++){
			line = line + " ";
		}
	}

	//add credit refund
	if (std::to_string(credit_refund).length() < 9){
		for (int i = 0; i < (9 - std::to_string(credit_refund).length()); i++){
			line = line + "0";
		}
	}
	line = line + std::to_string(credit_refund);

	//write to file
	file << line << endl;
	file.close();
	return 0;
}

//for sell and buy transactions
int Write_BuySell(string code, string event, string username_seller, int tickets, float price){
	ofstream file;
	file.open(TRANSACTION);

	if (!file.is_open()) return -1;

	//add code and event name
	line = code + " " + event;
	if (event.length() < 19){
		for (int i = 0; i < (19 - event.length()); i++){
			line = line + " ";
		}
	}

	//add seller's username_
	line = code + " " + username_seller;
	if (username_seller.length() < 15){
		for (int i = 0; i < (15 - username_seller.length()); i++){
			line = line + " ";
		}
	}

	//add number of tickets
	if (std::to_string(tickets).length() < 3){
		for (int i = 0; i < (3 - std::to_string(tickets).length()); i++){
			line = line + "0";
		}
	}
	line = line + std::to_string(tickets) + " ";

	//add price per ticket
	if (std::to_string(price).length() < 6){
		for (int i = 0; i < (6 - std::to_string(price).length()); i++){
			line = line + "0";
		}
	}
	line = line + std::to_string(price);

	//write to file
	file << line << endl;
	file.close();
	return 0;
}
