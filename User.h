#ifndef USER_H
#define USER_H

#include <string>

class User
{
	private:
		std::string username,
			password;

	public:
		User();
		User(const std::string&, const std::string&);
		std::string get_username() const;
		bool check(const std::string&, const std::string&) const;
		void set_password(const std::string&);
};

#endif
