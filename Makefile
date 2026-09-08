CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90
CFLAGS += -g0 -O2

NAME = hsh

SRC_DIR = src
OBJ_DIR = obj

SRC = simple_shell.c \
	_basename.c \
	_environ.c \
	_getenv.c \
	_isspace.c \
	_memset.c \
	_putchar.c \
	_strchr.c \
	_strcmp.c \
	_strdup.c \
	_strncmp.c \
	argslen.c \
	check_spaces.c \
	eof.c \
	err_malloc.c \
	execute.c \
	fatal.c \
	free_tokens.c \
	get_tokens.c \
	interactive.c \
	non_interactive.c \
	path.c \
	prompt.c \
	string.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS = $(SRC_DIR)/shell.h

.PHONY: all clean oclean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ) -r $(OBJ_DIR)

oclean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
