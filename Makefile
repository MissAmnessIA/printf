# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 20:12:49 by vmesa-ke          #+#    #+#              #
#    Updated: 2024/10/23 20:12:51 by vmesa-ke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
C_FILES			=	ft_printf.c basics.c put_type.c
O_FILES			=	$(patsubst %.c, %.o, ${C_FILES})

CC				=	cc
CFLAGS			=	-c -Wall -Werror -Wextra

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME) : ${O_FILES}
	ar rcs ${NAME} ${O_FILES}

%.o : %.c
	$(CC) $(CFLAGS) $?

clean : 
	-rm $(O_FILES)

fclean : clean
	-rm $(NAME)

re : fclean $(NAME)