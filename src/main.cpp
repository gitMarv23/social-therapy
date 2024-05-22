#include "BBoard.h"

int main(int argc, char *argv[])
{
	// std::cout << "\e[2J\e[1;1H";

	// Create a Bulletin Board.
	BBoard myBulletinBoard("My Fun Bulletin Board");

	// Setup user accounts with file of users and their passwords.
	myBulletinBoard.setup(argv[1]);

	// Allow the user to login with his credentials.
	myBulletinBoard.login();

	// Run the main loop of the bulletin.
	myBulletinBoard.run();

	return 0;
}
