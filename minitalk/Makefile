SRC = client.c
SRC1 = server.c

SRCBN = client_bonus.c
SRC1BN = server_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror


OBJS = $(SRC:.c=.o)
OBJS1 = $(SRC1:.c=.o)

OBJSBN = $(SRCBN:.c=.o)
OBJS1BN = $(SRC1BN:.c=.o)

NAME = client
NAME1 = server 

NAMEBN = client_bonus
NAME1BN = server_bonus

all: $(NAME) $(NAME1)

bonus: $(NAMEBN) $(NAME1BN)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) -o $@ $^

$(NAMEBN): $(OBJSBN)
	$(CC) $(CFLAGS) -o $@ $^
$(NAME1BN): $(OBJS1BN)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS1) $(OBJSBN) $(OBJS1BN)

fclean: clean
	rm -f $(NAME) $(NAME1) $(NAMEBN) $(NAME1BN)

re: fclean all

.PHONY: all clean fclean re