class Message:
    def __init__(self, author, subject, body):
        self.author = author
        self.subject = subject
        self.body = body

    def display(self):
        print(F"Subject: {self.subject}")
        print(F"Body: {self.body}")
