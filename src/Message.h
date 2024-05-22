#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

class Message
{
	private:
		std::string author,
			subject,
			body;
	
	public:
		Message();
		Message(const std::string&, const std::string&, const std::string&);
		void display() const;
};

#endif
