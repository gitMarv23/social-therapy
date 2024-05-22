#include "User.h"

User::User()
{
	this -> username = "";
	this -> password = "";
}

User::User(const std::string &uname, const std::string &passd)
{
	this -> username = uname;
	this -> password = passd;
}

std::string User::get_username() const
{
	return this -> username;
}

bool User::check(const std::string &uname, const std::string &passd) const
{
	if (uname == "")
	{
		return false;
	}
	else if ((this -> username == uname) && (this -> password == passd))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void User::set_password(const std::string &passd)
{
	int x = 0;
}
