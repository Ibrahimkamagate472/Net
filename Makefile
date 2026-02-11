CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = main
SRCS = main.cpp Network.cpp Person.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove build files
clean:
	rm -f $(OBJS) $(TARGET)

# Clean and rebuild
rebuild: clean all

.PHONY: all clean rebuild