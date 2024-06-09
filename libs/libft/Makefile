# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 22:14:40 by ohamadou          #+#    #+#              #
#    Updated: 2024/06/09 06:52:48 by ohamadou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = includes/

SRCS = ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_atoi.c ft_bzero.c \
	ft_calloc.c ft_isascii.c ft_isprint.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_strchr.c \
	ft_strdup.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_tolower.c ft_toupper.c \
	ft_strtrim.c ft_substr.c ft_split.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_strjoin.c\
	ft_strmapi.c ft_striteri.c ft_itoa.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	./ft_printf/ft_printchar.c \
	./ft_printf/ft_printnbr.c \
	./ft_printf/ft_printpercent.c \
	./ft_printf/ft_printptr.c \
	./ft_printf/ft_printstr.c \
	./ft_printf/ft_printunsigned.c \
	./ft_printf/ft_printf.c \
	./ft_printf/ft_printf_utils.c \
	./ft_printf/ft_printhex.c 

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c

GNL_SRCS = get_next_line/get_next_line_bonus.c \
		get_next_line/get_next_line_utils_bonus.c

OBJ = $(SRCS:.c=.o)

GNL_OBJS = $(GNL_SRCS:.c=.o)

BONUSOBJ = $(BONUS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc
#AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJS)
	ar rcs $(NAME) $(OBJ) $(GNL_OBJS)
# ranlib $(NAME)

# $(OBJ): $(SRCS)
# 	$(CC) $(CFLAGS) -c $(SRCS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUSOBJ) $(GNL_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUSOBJ)
	ar rcs $(NAME) $(OBJ) $(BONUSOBJ);

.PHONY: all fclean re bonus
