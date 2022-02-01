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
SRCS_PATH	 = srcs/
SRCS		 = $(SRCS_PATH)ft_printf.c $(SRCS_PATH)ft_printf_input.c $(SRCS_PATH)ft_token_hexa.c $(SRCS_PATH)ft_token_numbers.c
OBJS		 = $(SRCS:.c=.o)
BONUS		 =	ft_printf.c
BONUS_OBJS	 = $(BONUS:.c=.o)
CC			 = gcc
RM			 = rm -f
CFLAGS		 = -Wall -Wextra -Werror -c
INCLUDES	 = -I.includes/
NAME 		 = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)$(CFLAGS)$(INCLUDES)$(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
