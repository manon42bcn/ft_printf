# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 20:09:37 by mporras-          #+#    #+#              #
#    Updated: 2022/02/01 11:15:34 by mporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 = libftprintf.a
SRCS		 = srcs/ft_printf.c srcs/ft_printf_input.c srcs/ft_printf_utils.c srcs/ft_token_hexa.c \
			   srcs/ft_token_numbers.c srcs/ft_token_strings.c
OBJS		 = ft_printf.o ft_printf_input.o ft_printf_utils.o ft_token_hexa.o \
			   ft_token_numbers.o ft_token_strings.o
BONUS		 =	ft_printf.c
BONUS_OBJS	 = $(BONUS:.c=.o)
CC			 = gcc
RM			 = rm -f
CFLAGS		 = -Wall -Wextra -Werror -c
INCLUDES	 = -I.includes/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS):
	gcc -Wall -Wextra -Werror -c $(INCLUDES) $(SRCS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
