# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abchtaib <abchtaib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/31 16:11:52 by abchtaib          #+#    #+#              #
#    Updated: 2025/12/31 23:24:14 by abchtaib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SOURCE = ft_creat_list.c  ft_operation.c  ft_sort3.c  ft_sort.c	 push_swap.c \
			ft_operation2.c  ft_sort2.c	 ft_sort4.c  ft_split.c

BONUS = checker_bonus.c checker_bonus2.c checker_bonus3.c checker_bonus4.c \
			get_next_line.c get_next_line_utils.c ft_split.c

OBJECT = $(SOURCE:%.c=%.o)
BON = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJECT)
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(BON)
	$(CC) $(CFLAGS) $(BON) -o $(CHECKER)

clean:
	$(RM) $(OBJECT) $(BON)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re : fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: