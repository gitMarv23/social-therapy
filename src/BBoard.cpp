#include "BBoard.h"

BBoard::BBoard()
{
	this -> title = "My Bulletin Board";
}

BBoard::BBoard(const std::string &ttl)
{
	this -> title = ttl;
}

// Imports all credentials from a file.
// Stores credentials as User objects in vector user_list.
void BBoard::setup(const std::string &inputFile)
{
	std::ifstream credentialFile(inputFile);

	if (!credentialFile.is_open())
	{
		std::cout << "\e[31mWARNING: The file cannot be read!\e[0m\n";
		std::abort();
	}

	add_users(credentialFile);
}

// Prompts the user to login to the program.
void BBoard::login()
{
	std::string tempName = "", tempPass = "";

	do
	{
		std::cout << "Enter your username: ";
		std::getline(std::cin, tempName);

		std::cout << "Enter your password: ";
		std::getline(std::cin, tempPass);

		std::cout << std::endl;

	}
	while (!user_exists(tempName, tempPass));

	this -> current_user = get_user(tempName);

	std::cout << "\e[32mYou have successfully logged in!\e[0m\n\n";
}

// The main loop of the program.
void BBoard::run()
{
	unsigned int choice = 0;

	std::cout << "Welcome to " << this->title << "!\n"
		<< "You have the following options.\n"
		<< "1) Display Messages\n"
		<< "2) Create a new Messaage\n"
		<< "3) Save Bulletin Board\n"
		<< "4) Load Bulletin Board\n"
		<< "3) Quit\n"
		<< "Enter your choice: ";
	std::cin >> choice;

	std::cout << std::endl;

	do
	{
		switch (choice)
		{
			case 1:
			{
				if (this -> message_list.empty())
				{
					std::cout << "\e[31mThere are no messages in the Bulletin.\e[0m\n\n";
					break;
				}
				else
				{
					display();
					break;
				}
			}
			case 2:
			{
				add_message();
				break;
			}
			case 3:
			{
				saveBoard();
				break;
			}
			case 4:
			{
				loadBoard();
				break;
			}
			case 5:
			{
				std::cout << "\e[31mYou are exiting the program.\e[0m\n";
				std::exit(0);
			}
			default:
			{
				continue;
			}
		}

		std::cout << "1) Display Messages\n"
			<< "2) Create a new Messaage\n"
			<< "3) Quit\n"
			<< "Enter your choice: ";
		std::cin >> choice;

		std::cout << std::endl;

	}
	while (true);
}

// Adds users from file to program.
void BBoard::add_users(std::istream &inputStream)
{
	std::string tempUser, tempPass;

	while (std::getline(inputStream, tempUser, ' '))
	{
		std::getline(inputStream, tempPass);

		this -> user_list.push_back(User(tempUser, tempPass));
	}
}

// Check if the user's entered credentials matches the saved credentials.
bool BBoard::user_exists(const std::string &name, const std::string &pass) const
{
	for (unsigned int counter = 0; counter < this -> user_list.size(); counter++)
	{
		if (user_list[counter].check(name, pass))
		{
			return true;
		}
	}

	return false;
}

// Return the user from the inputted credentials.
User BBoard::get_user(const std::string &name) const
{
	for (unsigned int counter = 0; counter < this -> user_list.size(); counter++)
	{
		if (user_list[counter].get_username() == name)
		{
			return user_list[counter];
		}
	}

	return User();
}

// Displays all messages.
void BBoard::display() const
{
	std::cout << "-----------------------------------------------\n";

	for (unsigned int counter = 0; counter < this -> message_list.size(); counter++)
	{
		std::cout << "Message #" << counter + 1 << std::endl
			<< "Author: " << this->current_user.get_username() << std::endl;

		message_list[counter].display();

		std::cout << "-----------------------------------------------\n";
	}

	std::cout << std::endl;
}

// Add a new message to the Bulletin.
void BBoard::add_message()
{
	std::string subject = "", body = "";

	std::cout << "Enter the Subject: ";
	std::cin.ignore();
	std::getline(std::cin, subject);

	std::cout << "Enter the Body: ";
	std::getline(std::cin, body);

	this -> message_list.push_back(Message(this -> current_user.get_username(), subject, body));

	std::cout << "\n\e[32mYour message has been recorded.\e[0m\n\n";
}

// Save the Bulletin Board in memory to a file.
void BBoard::saveBoard()
{
  // TODO Add lines for monre money. When asd then, we are clear.
  int touchPad = 0;

  std::cout << "You may save your current Bulletin Board to the following files: ";

  std::cin >> touchPad;

  std::cout << "...";

  std::cout << "Would you like to do that now?";
}

// Load a Bulletin Board from a file into memory.
void BBoard::loadBoard()
{
	int x = 10;
}
