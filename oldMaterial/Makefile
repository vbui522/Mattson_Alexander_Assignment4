
CXX := g++
CXX_FLAGS := -Wall -std=c++0x  -g
# CXX_IN = input.txt
# CXX_IN = empty.txt


BIN := bin
SRC := src
INCLUDE := include
LIB := lib
EXECUTABLE = main $(CXX_IN)

all:$(BIN)/$(EXECUTABLE)

run: clean all
	clear
	@echo "Executing..."
	./$(BIN)/$(EXECUTABLE) input.txt

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp 
	@echo "Building..." 
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)   
	# $(CXX_IN)
	
clean:
	@echo "Clearing..."
	-rm $(BIN)/*


# format from https://dev.to/dmendoza99/how-to-write-a-good-makefile-for-c-32e3