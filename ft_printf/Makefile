# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 10:51:45 by ayassir           #+#    #+#              #
#    Updated: 2022/03/16 18:23:09 by ayassir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_putchar.c ft_puthex.c ft_puthexx.c ft_putnbr.c ft_putstr.c \
		ft_putptr.c ft_printf.c ft_putuns.c \

NAME =libftprintf.a
OBJS =$(SRCS:.c=.o)
CFLAGS =-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar -crs $@ $^
%.o: %.c
	@$(CC) $(CFLAGS) -c $^

clean:
	@rm -rf $(OBJS)
fclean: clean
	@rm -rf $(NAME)
re: fclean all
