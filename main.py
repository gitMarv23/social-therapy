from BBoard import BBoard
import sys

# Create a Bulletin Board.
myBulletinBoard = BBoard("My Fun Bulletin Board");

# Setup user accounts with file of users and their passwords.
myBulletinBoard.setup(sys.argv[1]);

# Allow the user to login with his credentials.
myBulletinBoard.login();

# Run the main loop of the bulletin.
myBulletinBoard.run();
