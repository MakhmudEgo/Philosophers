# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/01 09:16:47 by mizola            #+#    #+#              #
#    Updated: 2020/11/19 05:25:01 by mizola           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	philo_three

SRC =		ft_atoi.c ft_itoa.c philosophers.c ft_str_for_msg.c \
			ft_join_3_ptr.c ft_start.c ft_utils.c ft_free_xxx.c

FLAGS =		-Wall -Wextra -Werror

OSRC =		$(SRC:.c=.o)

HEADER =	philosophers.h

all:		$(NAME)

$(NAME):	$(OSRC)
			gcc $(FLAGS) $(OSRC) -o $(NAME)

%.o:		%.c $(HEADER)
			gcc $(FLAGS) -c $< -o $@

clean:
			rm -rf  $(OSRC)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

n:
			norminette *.c *.h
s:
			wc *.c *.h

.PHONY:		all clean fclean re n s
