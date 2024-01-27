CXX = g++
CFLAGS = -g -std=c++17 -Wall

EXECUTABLE = main
SOURCE = YourFile.cpp 

$(EXECUTABLE): $(SOURCE)
	$(CXX) $(CFLAGS) -o $(EXECUTABLE) $(SOURCE)
 

clean:
	rm -f *~ *.o main


