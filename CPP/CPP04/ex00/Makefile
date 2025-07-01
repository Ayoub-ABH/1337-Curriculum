CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = ex00

HEADER = Animal.hpp  Cat.hpp  Dog.hpp WrongAnimal.hpp WrongCat.hpp
SRCS = Animal.cpp  Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
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
