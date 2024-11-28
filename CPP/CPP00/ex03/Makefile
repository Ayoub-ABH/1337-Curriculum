CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = account


SRCS =  Account.cpp tests.cpp
HEADERS = Account.hpp

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