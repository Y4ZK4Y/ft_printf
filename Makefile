# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ykarimi <ykarimi@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/15 10:39:43 by ykarimi       #+#    #+#                  #
#    Updated: 2024/01/15 10:39:46 by ykarimi       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

# Compilation
CFLAGS := -Wall -Wextra -Werror
CC := cc

SRC := ft_printf.c print_functions.c

HEADER := ft_printf.h

BUILD_DIR := ./build

OBJECTS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))

all: $(NAME)

$(BUILD_DIR)/%.o: %.c $(HEADER)
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re