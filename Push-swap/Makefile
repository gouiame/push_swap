# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 21:35:26 by cgouiame          #+#    #+#              #
#    Updated: 2023/05/27 20:43:58 by cgouiame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra
FILES = instractions.c instractions1.c  instractions2.c push_swap.c sorting.c \
		split.c utils.c utils2.c sorting2.c

OBJ= $(FILES:.c=.o)
NAME = push_swap

all : $(NAME)

$(NAME): $(OBJ) 
		 		$(CC) $(OBJ) -o $(NAME)  
						
%.o : %.c push_swap.h
		$(CC) $(FLAGS) -c $< 											

clean :
		 rm -f $(OBJ)

fclean : clean
		 rm -f $(NAME)

re : fclean all