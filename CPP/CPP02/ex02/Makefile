CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = fixed
SRCS = main.cpp Fixed.cpp
HEADER = Fixed.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp  $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: clean all

.PHONY: clean
