a.out: main.o BBoard.o Message.o User.o
	g++ main.o BBoard.o Message.o User.o
	make clean

main.o: main.cpp
	g++ -c main.cpp

BBoard.o: BBoard.cpp
	g++ -c BBoard.cpp

Message.o: Message.cpp
	g++ -c Message.cpp

User.o: User.cpp
	g++ -c User.cpp

clean:
	rm *.o
