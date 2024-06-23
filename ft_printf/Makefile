SCRS = 	ft_putchar.c ft_putstr.c ft_putptr.c ft_putint.c\
		ft_putunsigned.c ft_puthex.c ft_printf.c

OBJS = ${SCRS:.c=.o}


NAME = libftprintf.a 
LIBC = ar rcs
RM = rm -f
CC = cc 
CFALGS = -Wall -Wextra -Werror

%.o : %.c ft_printf.h
	${CC} $(CFLAGS) -c $< -o $@

${NAME} : ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all : ${NAME}

clean : 
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re