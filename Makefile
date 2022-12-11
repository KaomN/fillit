NAME= fillit
SOURCES= fillit.c free.c map.c solver.c tetrimino.c validator.c
HEADER= libft/
LIBFT= libft/libft.a
FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SOURCES) $(LIBFT) $(HEADER)
	@gcc $(FLAGS) $(SOURCES) $(LIBFT) -I $(HEADER) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	@rm -f $(wildcard *.o)

fclean: clean
	make -C libft fclean
	@rm -f $(NAME)

re: fclean all