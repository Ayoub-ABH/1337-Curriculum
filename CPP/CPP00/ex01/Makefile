CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = phonebook


SRCS =  Contact.cpp PhoneBook.cpp main.cpp
HEADERS = Contact.hpp PhoneBook.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: clean all

.PHONY: clean