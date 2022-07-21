# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 15:38:45 by alee              #+#    #+#              #
#    Updated: 2022/07/21 00:07:27 by alee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = GCC
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = cub3D

FILE = main cub3d

LIBFT_FILE = ft_isalnum ft_isprint ft_memcmp ft_putchar_fd ft_split \
	ft_strlcat ft_strncmp ft_substr ft_atoi ft_isalpha \
	ft_itoa ft_memcpy ft_putendl_fd ft_strchr ft_strlcpy \
	ft_strnstr ft_tolower ft_bzero ft_isascii ft_memccpy \
	ft_memmove ft_putnbr_fd ft_strdup ft_strlen ft_strrchr \
	ft_toupper ft_calloc ft_isdigit ft_memchr ft_memset \
	ft_putstr_fd ft_strjoin ft_strmapi ft_strtrim ft_strcmp

GNL_FILE = get_next_line

UTILS_FILE = ft_utils_01 debug

PARSE_FILE = file_loader parse_data content_checker

LIBFT_SRC = $(addprefix libft/,$(addsuffix .c, $(LIBFT_FILE)))
GNL_SRC = $(addprefix get_next_line/,$(addsuffix .c, $(GNL_FILE)))
UTILS_SRC = $(addprefix utils/,$(addsuffix .c, $(UTILS_FILE)))
PARSE_SRC = $(addprefix parse/,$(addsuffix .c, $(PARSE_FILE)))

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)
PARSE_OBJ = $(PARSE_SRC:.c=.o)

SRC = $(addsuffix .c, $(FILE)) $(LIBFT_SRC) $(GNL_SRC) $(UTILS_SRC) $(PARSE_SRC)
OBJ = $(addsuffix .o, $(FILE)) $(LIBFT_OBJ) $(GNL_OBJ) $(UTILS_OBJ) $(PARSE_OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
