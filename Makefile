# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 09:24:14 by lboulang          #+#    #+#              #
#    Updated: 2023/04/21 17:08:47 by lboulang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

NAME_BONUS = checker

LIBFT = ./srcs/libft/libft.a

FT_PRINTF = ./srcs/ft_printf/libftprintf.a

SRCS = ./srcs/mandatory/main.c\
		./srcs/mandatory/parsing/init_list.c\
		./srcs/mandatory/parsing/parse.c\
		./srcs/mandatory/parsing/tools.c\
		./srcs/mandatory/mooves/mooves.c\
		./srcs/mandatory/mooves/plist.c\
		./srcs/mandatory/algo/algo_little.c\
		./srcs/mandatory/algo/algo_big.c\
		./srcs/mandatory/algo/handle_price.c\
		./srcs/mandatory/algo/handle_parent_price.c

SRCS_BONUS = ./srcs/bonus/parsing/parse_bonus.c\
			./srcs/bonus/parsing/init_list_bonus.c\
			./srcs/bonus/parsing/boosted_gnl.c\
			./srcs/bonus/exec/mooves_bonus.c\
			./srcs/bonus/exec/exec_mooves.c\
			./srcs/bonus/main_bonus.c\
			./srcs/bonus/plist_bonus.c\
			./srcs/bonus/tools_bonus.c\

OBJS = ${SRCS:.c=.o }
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc
CFLAGS = -g3 -Wall -Werror -Wextra -I .

all: ${NAME}

$(NAME) : ${OBJS}
	make -C srcs/libft/
	make -C srcs/ft_printf/
	$(CC) ${OBJS} ${LIBFT} ${FT_PRINTF} -o ${NAME}

bonus : ${OBJS_BONUS}
	make -C srcs/libft/
	make -C srcs/ft_printf/
	$(CC) ${OBJS_BONUS} ${LIBFT} ${FT_PRINTF} -o ${NAME_BONUS}

clean : 
	make clean -C srcs/libft/
	make clean -C srcs/ft_printf/
	rm -rf ${OBJS} ${OBJS_BONUS}
	
fclean : clean
	make fclean -C srcs/libft/
	rm -rf ${LIBFT}
	make fclean -C srcs//ft_printf/
	rm -rf ${FT_PRINTF}
	rm -rf ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY	: all clean fclean re