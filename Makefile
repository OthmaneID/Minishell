FILES = minishell.c  utils.c GNL/get_next_line.c  \
		GNL/get_next_line_utils.c minishell_utiles.c minishell_utiles2.c ft_split.c \
		export_var.c export_var2.c export_parse.c

OBJ = ${FILES:.c=.o}

NAME = minishell

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)
$(NAME): $(OBJ)
	@cc $(CFLAGS) -lreadline ${OBJ} -o ${NAME}
clean:
	@rm -rf ${OBJ}
	@echo "cleaning Object files ..."
fclean: clean
	@rm -f ${NAME}
	@echo "cleaning Executable file ..."
re : fclean all