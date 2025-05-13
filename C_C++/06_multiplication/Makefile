# Makefile für 05_ex_basins

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

TARGET = 06_mul
SRC = 06_mul.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o *.ppm

