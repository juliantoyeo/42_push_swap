# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyeo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 14:15:58 by jyeo              #+#    #+#              #
#    Updated: 2018/01/25 00:00:51 by jyeo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PUSH = push_swap

FLAG = -Wall -Wextra -Werror

CC = gcc

SRC =       		srcs/choose_sort.c\
      				srcs/display.c\
      				srcs/game.c\
      				srcs/move.c\
      				srcs/operation.c\
      				srcs/parsing.c\
      				srcs/push_swap_sort.c\
      				srcs/rank.c\
      				srcs/simple_1.c\
      				srcs/simple_2.c\
      				srcs/simple_utils.c\
      				srcs/sort_1.c\
      				srcs/sort_2.c\
      				srcs/sort_3.c\
      				srcs/sort_4.c\
      				srcs/sub_utils.c\
      				srcs/utils.c\
      				srcs/zone_utils.c\

CHECKER_SRC = 		srcs/checker.c\

PUSH_SRC = 			srcs/push_swap.c\

INCLUDES = -I includes

OBJ = $(SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
PUSH_OBJ = $(PUSH_SRC:.c=.o)
LIBS = -L libft/ -lft

ALL_OBJ = $(OBJ) $(CHECKER_OBJ) $(PUSH_OBJ)

all: lib $(ALL_OBJ)
	
lib:
	make -C libft/

$(OBJ): %.o: %.c
	$(CC) $(FLAG) $(INCLUDES) -c $^ -o $@

$(CHECKER_OBJ): %.o: %.c
	$(CC) $(FLAG) $(INCLUDES) -c $^ -o $@
	$(CC) $(FLAG) -o $(CHECKER) $(OBJ) $(CHECKER_OBJ) $(LIBS)

$(PUSH_OBJ): %.o: %.c
	$(CC) $(FLAG) $(INCLUDES) -c $^ -o $@
	$(CC) $(FLAG) -o $(PUSH) $(OBJ) $(PUSH_OBJ) $(LIBS)

clean:
	@/bin/rm -f $(ALL_OBJ)
	make clean -C libft/

fclean:	clean
	@/bin/rm -f $(CHECKER)
	@/bin/rm -f $(PUSH)
	make fclean -C libft/

re:	fclean all
