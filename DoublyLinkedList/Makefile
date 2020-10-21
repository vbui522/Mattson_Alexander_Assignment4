
CXXFLAGS = -std=c++0x

main: main.o ItemType.o DoublyLinkedList.o
		$(CXX) $(CXXFLAGS) -o main main.o ItemType.o DoublyLinkedList.o
main.o: main.cpp ItemType.h DoublyLinkedList.h
		$(CXX) $(CXXFLAGS) -c main.cpp
DoublyLinkedList.o: DoublyLinkedList.h ItemType.h

clean:
		rm -rf *.o
		rm -rf main
compile:
		g++ $(CXXFLAGS) -c main.cpp
		g++ $(CXXFLAGS) -c DoublyLinkedList.cpp
		g++ $(CXXFLAGS) -c ItemType.cpp
		g++ -o main main.o ItemType.o DoublyLinkedList.o
run:
		g++ $(CXXFLAGS) -c main.cpp
		g++ $(CXXFLAGS) -c DoublyLinkedList.cpp
		g++ $(CXXFLAGS) -c ItemType.cpp
		g++ -o main main.o ItemType.o DoublyLinkedList.o

		./main input.txt
