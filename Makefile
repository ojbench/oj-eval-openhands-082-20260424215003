CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall

code: main.cpp src.hpp
	$(CXX) $(CXXFLAGS) -o code main.cpp

clean:
	rm -f code
