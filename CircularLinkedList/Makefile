
CXXFLAGS = -std=c++0x

main: main.o ItemType.o CircularLinkedList.o
		$(CXX) $(CXXFLAGS) -o main main.o ItemType.o CircularLinkedList.o
main.o: main.cpp ItemType.h CircularLinkedList.h
		$(CXX) $(CXXFLAGS) -c main.cpp
CircularLinkedList.o: CircularLinkedList.h ItemType.h

clean:
		rm -rf *.o
		rm -rf main
compile:
		g++ -std=c++0x -c main.cpp
		g++ -std=c++0x -c CircularLinkedList.cpp
		g++ -std=c++0x -c ItemType.cpp
		g++ -std=c++0x -o main main.o ItemType.o CircularLinkedList.o
run:
		g++ -std=c++0x -c main.cpp
		g++ -std=c++0x -c CircularLinkedList.cpp
		g++ -std=c++0x -c ItemType.cpp
		g++ -o main main.o ItemType.o CircularLinkedList.o

		./main input.txt
