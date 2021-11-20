SRC = ft_atoi.c\
ft_putchar.c\
ft_putendl.c\
ft_putnbr.c\
ft_putstr.c\
ft_printf.c

OBJ = ft_atoi.o\
ft_putchar.o\
ft_putendl.o\
ft_putnbr.o\
ft_putstr.o\
ft_printf.o

CC = gcc -Wall -Wextra -Werror

NAME = libft.a

all : $(NAME)
	
$(NAME) : $(OBJ)

%.o: %.c
	CC -c $<
	ar -rc $(NAME) $@
	
clean : 
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean all