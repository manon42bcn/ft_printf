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

NAME			=	libftprintf.a
MANDATORY		=	mandatory
SRC_DIR			=	mandatory
OBJS_DIR		=	mandatory/obj
OBJS_SUBS		=	$(OBJS_DIR)
SRCS			=	ft_printf.c \
				 	ft_token_numbers.c \
				 	ft_token_strings.c \
				 	ft_token_process.c
OBJS 			=	$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
SRC_DIR_BONUS 	= 	bonus
OBJS_DIR_BONUS	= 	bonus/obj
SRCS_BONUS	 	= 	ft_printf_bonus.c \
			 	  	ft_printf_input_bonus.c \
			 	  	ft_printf_utils_bonus.c \
			 	  	ft_token_hexa_bonus.c \
			 	  	ft_token_numbers_bonus.c \
			 	  	ft_token_process_bonus.c \
			 	  	ft_token_strings_bonus.c
OBJS_BONUS		=	$(addprefix $(OBJS_DIR_BONUS)/,$(SRCS_BONUS:.c=.o))
CC			 	= 	gcc
RM			 	= 	rm	-rf
CFLAGS		 	= 	-Wall -Wextra -Werror -c
INCLUDES	 	= 	-I.	mandatory/inc/ft_printf.h
INCLUDES_BNS 	= 	-I.	includes/ft_printf_bonus.h
BONUS_FLAG		=	.bonus

all: version $(NAME)

version:
	@if [ -f .bonus ]; then \
  		rm $(BONUS_FLAG); \
		$(MAKE) fclean; \
		$(MAKE); \
	fi

$(NAME): $(OBJS_SUBS) $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar	rcs	$(NAME)	$(OBJS)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) -Iinc $(CFLAGS) -g -c $< -o $@

$(OBJS_DIR):
	-@mkdir $(OBJS_DIR)

bonus: version_bonus $(BONUS_FLAG)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar	rcs	$(NAME)	$(OBJS_BONUS)

version_bonus:
	@if [ ! -f $(BONUS_FLAG) ] && [ -f $(NAME) ]; then \
		$(MAKE) fclean; \
    fi

$(BONUS_FLAG): $(OBJS_DIR_BONUS) $(OBJS_BONUS)

$(OBJS_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c bonus/inc/ft_printf_bonus.h
	$(CC) -Iinc $(CFLAGS) -g -c $< -o $@
	@touch $(BONUS_FLAG)

$(OBJS_DIR_BONUS):
	-@mkdir $(OBJS_DIR_BONUS)

clean:
	$(MAKE) -C ./libft fclean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)
	@$(RM) $(OBJS_DIR)
	@$(RM) $(OBJS_DIR_BONUS)
	@$(RM) $(BONUS_FLAG)

re:	fclean $(NAME)

.PHONY: all clean fclean re bonus
