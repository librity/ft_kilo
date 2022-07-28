# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/25 22:59:46 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/07/28 13:07:13 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kilo

CC = gcc
CCFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

MAIN = $(addsuffix .o, $(NAME) )

SOURCES = kilo.c src/control.c src/errors.c src/tty_config.c src/tty_utilities.c src/editor.c src/editor_utilities.c
OBJECTS = $(subst .c,.o,$(SOURCES))
DEPENDENCIES = includes/kilo.h

all: $(NAME)

clean:
	rm -f $(NAME) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

$(OBJECTS): %.o : %.c $(DEPENDENCIES)
	$(CC) -c -o $@ $< $(CCFLAGS)

$(NAME): % : $(filter-out $(MAIN), $(OBJECTS)) %.o
	$(CC) -o $@ $(LIBS) $^ $(CCFLAGS) $(LDFLAGS)

.PHONY: all re \
	clean fclean
