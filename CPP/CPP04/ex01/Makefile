CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = ex01

HEADER = Animal.hpp Brain.hpp Cat.hpp Dog.hpp
SRCS = Animal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: clean all

.PHONY: clean
