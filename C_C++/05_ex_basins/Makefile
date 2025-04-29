# Makefile für 05_ex_basins

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

TARGET = 05_ex_basins
SRC = 05_ex-basins.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o *.ppm

