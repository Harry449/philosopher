# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kharigae <kharigae@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 18:58:18 by kharigae          #+#    #+#              #
#    Updated: 2022/08/03 03:38:42 by kharigae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = src/main.c \
		src/error.c \
		src/init.c \
		src/itoa.c \
		src/kill.c \
		src/counter.c \
		src/prosess.c \
		src/routine.c \
		src/routine_utils.c \
		src/store_argument.c \
		src/strjoin.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -pthread

DEBUG = -g -fsanitize=address -fsanitize=undefined -fsanitize=integer

LEAK = -g -fsanitize=leak

CC = cc

RM = rm -f

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCS) -o $(NAME)

all : $(NAME)

re : fclean all

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

debug :
	clang $(CFLAGS) $(DEBUG) $(SRCS) -o $(NAME)

leak :
	clang $(CFLAGS) $(LEAK) $(SRCS) -o $(NAME)

.PHONY : all re clean fclean debug leak
