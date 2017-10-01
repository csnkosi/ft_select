# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 10:14:29 by cnkosi            #+#    #+#              #
#    Updated: 2017/08/24 16:04:45 by cnkosi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

HEADER = ft_select.h

SRC = main.c	ft_select.c		ft_canonical.c

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/

TERMCAP = -ltermcap

CFLAGS = #-Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	@gcc $(CFLAGS) -c $(SRC) $(HEADER)
	@gcc -o $(NAME) $(OBJ) -L$(LIBFT) -lft $(TERMCAP)
	@clear
	@echo "Your ft_select has been compiled successfully"

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean
	@clear
	@echo "Objects are now removed"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@clear
	@echo "Everything is now clean"

re: fclean all

norm:
	@clear
	@echo "Normenette ft_select"
	@norminette ft_select.h	main.c
