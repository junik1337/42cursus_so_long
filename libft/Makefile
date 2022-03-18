# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 17:29:02 by ayassir           #+#    #+#              #
#    Updated: 2022/03/16 18:23:16 by ayassir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_itoa.c ft_split.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_striteri.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_strjoin.c ft_atoi.c ft_bzero.c \
		ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
		ft_toupper.c ft_substr.c \
		
SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		 ft_lstclear.c ft_lstiter.c ft_lstmap.c \

NAME =libft.a
OBJS =$(SRCS:.c=.o)
OBJS_B =$(SRCS_B:.c=.o)
CFLAGS =-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar -crs $@ $^
bonus: $(OBJS_B) $(OBJS)
	@ar -crs $(NAME) $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $^

clean:
	@rm -rf $(OBJS) $(OBJS_B)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus