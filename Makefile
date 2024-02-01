NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

SRC  = 	ft_printf.c \
		ft_printf_utils.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(FLAGS) -c $(SRC)
	@$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)


fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re.