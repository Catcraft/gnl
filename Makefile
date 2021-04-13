# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 08:32:01 by ninieddu          #+#    #+#              #
#    Updated: 2021/04/12 08:32:48 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC		=	gcc -Wall -Wextra -Werror

NAME	=	libgnl.a

SRCS	=	get_next_line.c\
			get_next_line_utils.c

OPATH	=	objs/

OBJS	=	$(SRCS:%.c=$(OPATH)%.o)

all: $(NAME)

$(OPATH)%.o	:	%.c
				$(shell mkdir -p objs)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(OPATH)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all fclean clean re
