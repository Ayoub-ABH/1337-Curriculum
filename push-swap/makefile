SRCS = 	./actions/action_pa.c ./actions/action_pb.c ./actions/action_ra.c ./actions/action_rb.c \
		./actions/action_rr.c ./actions/action_rra.c ./actions/action_rrb.c ./actions/action_rrr.c \
		./actions/action_sa.c ./actions/action_sb.c ./actions/action_ss.c \
		./utils/action_stack.c ./utils/get_liss.c ./utils/get_min_cost.c ./utils/is_sorted.c \
		./utils/parse_stack.c ./utils/push_arg.c ./utils/index_x.c\
		./push_swap.c ./append_liss.c ./fill_stack.c sort_stack.c ./sort_x.c\

SRCSB = ./bonus/actions/action_pa.c ./bonus/actions/action_pb.c ./bonus/actions/action_ra.c ./bonus/actions/action_rb.c \
		./bonus/actions/action_rr.c ./bonus/actions/action_rra.c ./bonus/actions/action_rrb.c ./bonus/actions/action_rrr.c \
		./bonus/actions/action_sa.c ./bonus/actions/action_sb.c ./bonus/actions/action_ss.c \
		./bonus/get_next_line/get_next_line_bonus.c ./bonus/get_next_line/get_next_line_utils_bonus.c \
		./bonus/action_stack_bonus.c ./bonus/checker.c ./bonus/execute_acts_bonus.c ./bonus/fill_stack_bonus.c \
		./bonus/is_sorted_bonus.c ./bonus/parse_bonus.c \

SRCLIBFT = ./libft/ft_itoa.c ./libft/ft_atol.c ./libft/ft_putstr_fd.c	./libft/ft_strmapi.c\
		./libft/ft_atoi.c	./libft/ft_memchr.c	./libft/ft_split.c	./libft/ft_strncmp.c\
		./libft/ft_bzero.c	./libft/ft_memcmp.c	./libft/ft_strchr.c	./libft/ft_strnstr.c\
		./libft/ft_calloc.c	./libft/ft_memcpy.c	./libft/ft_strdup.c	./libft/ft_strrchr.c\
		./libft/ft_isalnum.c	./libft/ft_memmove.c	./libft/ft_striteri.c	./libft/ft_strtrim.c\
		./libft/ft_isalpha.c	./libft/ft_memset.c	./libft/ft_strjoin.c	./libft/ft_substr.c \
		./libft/ft_isascii.c	./libft/ft_putchar_fd.c	./libft/ft_strlcat.c	./libft/ft_tolower.c \
		./libft/ft_isdigit.c	./libft/ft_putendl_fd.c	./libft/ft_strlcpy.c	./libft/ft_toupper.c \
		./libft/ft_isprint.c	./libft/ft_putnbr_fd.c	./libft/ft_strlen.c \
		./libft/ft_lstnew_bonus.c ./libft/ft_lstadd_front_bonus.c \
		./libft/ft_lstsize_bonus.c ./libft/ft_lstlast_bonus.c \
		./libft/ft_lstadd_back_bonus.c ./libft/ft_lstdelone_bonus.c \
		./libft/ft_lstclear_bonus.c ./libft/ft_lstiter_bonus.c \
		./libft/ft_lstmap_bonus.c 


OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)


libft = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
NAMEB = checker

all: $(NAME)

$(libft) : $(SRCLIBFT)  ./libft/libft.h
	make -C ./libft 

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(libft) $(OBJSB) 
	$(CC) $(CFLAGS) $(OBJSB) $(libft) -o $(NAMEB)

$(NAME): $(libft) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(libft) -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJSB)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME) $(NAMEB)
	make -C ./libft fclean

re: fclean all

.PHONY: clean LIBFT LIBFTB