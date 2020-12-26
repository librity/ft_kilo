# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/25 22:59:46 by lpaulo-m          #+#    #+#              #
#    Updated: 2020/12/25 23:26:32 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

TARGET = kilo
MAIN = $(addsuffix .o, $(TARGET) )

SOURCES = kilo.c tty_config.c
OBJECTS = $(subst .c,.o,$(SOURCES))
DEPENDENCIES = kilo.h

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)

$(OBJECTS): %.o : %.c $(DEPENDENCIES)
	$(CC) -c -o $@ $< $(CCFLAGS)

$(TARGET): % : $(filter-out $(MAIN), $(OBJECTS)) %.o
	$(CC) -o $@ $(LIBS) $^ $(CCFLAGS) $(LDFLAGS)
