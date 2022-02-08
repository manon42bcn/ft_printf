# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 20:09:37 by mporras-          #+#    #+#              #
#    Updated: 2022/02/08 00:38:53 by mporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 = libftprintf.a
SRC_DIR		 = srcs
SRCS_FILES	 = ft_printf.c \
			   ft_token_numbers.c \
			   ft_token_strings.c \
			   ft_token_process.c
BONUS_FILES	 = ft_printf_bonus.c \
			   ft_printf_input_bonus.c \
			   ft_printf_utils_bonus.c \
			   ft_token_hexa_bonus.c \
			   ft_token_numbers_bonus.c \
			   ft_token_process_bonus.c \
			   ft_token_strings_bonus.c
BONUS_SRCS	 = $(addprefix $(SRC_DIR)/,$(BONUS_FILES))
BONUS_OBJS	 = $(BONUS_FILES:.c=.o)
SRCS 		 = $(addprefix $(SRC_DIR)/,$(SRCS_FILES))
OBJS		 = $(SRCS_FILES:.c=.o)
CC			 = gcc
RM			 = rm	-f
CFLAGS		 = -Wall -Wextra -Werror -c
INCLUDES	 = -I.	includes/ft_printf.h
INCLUDES_BNS = -I.	includes/ft_printf_bonus.h

all: $(NAME)
 
$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar	rcs	$(NAME)	$(OBJS)
	ranlib $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)

bonus: $(BONUS_OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar	rcs	$(NAME)	$(BONUS_OBJS)
	ranlib $(NAME)

$(BONUS_OBJS): $(BONUS_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES_BNS) $(BONUS_SRCS)

clean:
	$(MAKE) -C ./libft fclean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re bonus
