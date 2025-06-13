from User import User
from Message import Message
import sys

class BBoard:
    def __init__(self, title = "My Bulletin Board"):
        self.title = title
        self.user_list = []
        self.current_user = User("", "")
        self.message_list = []
        
    # Imports all credentials from a file.
    # Stores credentials as User objects in vector user_list.
    def setup(self, input_file):

        with open(input_file) as file:
            temp_user = ""
            temp_pass = ""
            
            user_credentials = file.readlines()
            for user in user_credentials:
                self.user_list.append(User(temp_user, temp_pass))

    # Prompts the user to login to the program.
    def login(self):
        temp_name = ""
        temp_pass = ""

        while True:
            temp_name = input("Enter your username: ")
            temp_pass = input("Enter your password: ")
            
            if not self.user_exists(temp_name, temp_pass):
                break

        self.current_user = self.get_user(temp_name)

        print("You have successfully logged in!\n\n")

    # The main loop of the program.
    def run(self):
    
        choice = 0
        choice = int(input(F"Welcome to {self.title}!\n"
             "You have the following options.\n"
             "1) Display Messages\n"
             "2) Create a new Messaage\n"
             "3) Quit\n"
             "Enter your choice: "))
        print()

        while True:
            match choice:
                case 1:
                    if not self.message_list:
                        print("There are no messages in the Bulletin.\n\n")
                    else:
                        self.display()
                case 2:
                    self.add_message()
                case 3:
                    print("You are exiting the program.\n")
                    sys.exit(0)
                case _:
                    continue

            choice = int(input("1) Display Messages\n"
                 "2) Create a new Messaage\n"
                 "3) Quit\n"
                 "Enter your choice: "))

            print()

    # Check if the user's entered credentials matches the saved credentials.
    def user_exists(self, name, passd):
        
        for user in self.user_list:
            if user.check(name, passd):
                return True
        return False

    # Return the user from the inputted credentials.
    def get_user(self, name):

        for user in self.user_list:
            if user.get_username() == name:
                return user
        return User("", "")
    
    # Displays all messages.
    def display(self):
        print("-----------------------------------------------")

        for index, message in enumerate(self.message_list, start = 1): 
            print(F"Message #{index}")
            print(F"Author: {self.current_user.get_username()}")
            
            message.display()

            print("-----------------------------------------------")
        
        print()
    
    # Add a new message to the Bulletin.
    def add_message(self):
        subject = ""
        body = ""

        subject = input("Enter the Subject: ")
        body = input("Enter the Body: ")

        self.message_list.append(Message(self.current_user.get_username(), subject, body))

        print("Your message has been recorded.\n\n")
