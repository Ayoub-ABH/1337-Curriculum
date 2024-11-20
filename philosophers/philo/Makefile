COMPILER = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
HEADER = philo.h
NAME = philo

SRCS =  init.c monitoring.c  set.c utils.c \
 get.c main.c simulate.c philo_routine.c clean.c

OBJS = ${SRCS:.c=.o}

all : $(NAME)

%.o : %.c $(HEADER)
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(COMPILER) $(CFLAGS) $^ -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean