CC=clang
GFLAGS=-Werror -Wextra -Wall -I libft/includes -I includes
LFLAGS=-L libft/ -lft
NAME=fillit
SRC=main.c verify.c
_SRC=$(SRC:%=src/%)

_OBJ=$(SRC:%.c=%.o)
OBJ=$(_OBJ:%=obj/%)

.PHONY: clean fclean all re norm norme

VPATH = src obj libft/includes includes src/str

$(NAME): $(_OBJ)
	@make -C libft
	@$(CC) -g -o $(NAME) $(OBJ) $(LFLAGS)

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	@$(CC) -g $(GFLAGS) -o obj/$@ -c $<

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

norm:
	norminette $(_SRC) includes/*

norme: norm