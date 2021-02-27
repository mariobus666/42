# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbus <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 14:02:48 by mbus              #+#    #+#              #
#    Updated: 2021/02/22 10:38:13 by mbus             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc
AR = ar rc
RM = rm -f

BSRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	   ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	   ft_itoa.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c \
	   ft_strlcat.c ft_substr.c ft_putendl_fd.c ft_strlcpy.c ft_tolower.c \
	   ft_putnbr_fd.c ft_strlen.c ft_toupper.c ft_putstr_fd.c ft_strmapi.c \
	   ft_split.c ft_strncmp.c ft_strchr.c ft_strnstr.c ft_strdup.c \
	   ft_strrchr.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	   ft_memmove.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(BOBJS) $(OBJS)
	$(AR) $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
