CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic

subarreglo: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o subarreglo

clean:
	rm -f subarreglo

.PHONY: clean
