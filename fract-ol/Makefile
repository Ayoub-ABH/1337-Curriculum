SRCS = hooks.c main.c utils.c julia.c mandelbrot.c  init_draw_fractals.c
SRCSBN = bonus/burning_ship_bonus.c bonus/julia_bonus.c  bonus/main_bonus.c \
		bonus/hooks_bonus.c        bonus/mandelbrot_bonus.c \
		bonus/init_draw_fractals_bonus.c bonus/utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJSBN = $(SRCSBN:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
NAME = fractol
NAMEBN = fractol_bonus

%.o: %.c fractol.h bonus/fractol_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $(NAME)

bonus: $(OBJSBN)
	$(CC) $(CFLAGS) $(MLX) $(OBJSBN) -o $(NAMEBN)

clean:
	$(RM) $(OBJS) $(OBJSBN)

fclean: clean
	$(RM) $(NAME) $(NAMEBN)

re: fclean all