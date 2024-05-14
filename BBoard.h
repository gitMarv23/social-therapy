#ifndef BBOARD_H
#define BBOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Message.h"
#include "User.h"

class BBoard
{
	private:
		std::string title;
		std::vector <User> user_list;
		User current_user;
		std::vector <Message> message_list;
		
		void add_users(std::istream&);
		bool user_exists(const std::string&, const std::string&) const;
		User get_user(const std::string&) const;
		void display() const;
		void add_message();
	
	public:
		BBoard();
		BBoard(const std::string&);
		void setup(const std::string&);
		void login();
		void run();
};

#endif
