class User:
    def __init__(self, username, password):
        self.username = username
        self.password = password

    def get_username(self):
        return self.username

    def check(self, uname, passd):
        if uname == "":
            return False
        elif (self.username == uname) and (self.password == passd):
            return True
        else:
            return False

    def set_password(self, passd):
        self.password = passd
