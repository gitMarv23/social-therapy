#include "Message.h"
	
Message::Message()
{
	this -> author = "";
	this -> subject = "";
	this -> body = "";
}

Message::Message(const std::string &athr, const std::string &sbjct, const std::string &body)
{
	this -> author = athr;
	this -> subject = sbjct;
	this -> body = body;
}

void Message::display() const
{
	std::cout << "Subject: " << this -> subject << std::endl
		<< "Body: " << this -> body << std::endl;
}
