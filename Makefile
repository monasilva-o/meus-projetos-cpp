CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = sistema-eventos
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run