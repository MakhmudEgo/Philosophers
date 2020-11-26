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

all:
	make	-C philo_one fclean
	make	-C philo_two fclean
	make	-C philo_three fclean
	rm		-rfv philo_one/philo_one.dSYM \
				philo_two/philo_two.dSYM \
				philo_three/philo_three.dSYM \
				1 2 3


1:
	make	-C philo_one
	mv		./philo_one/philo_one ./1
2:
	make	-C philo_two
	mv		./philo_two/philo_two ./2
3:
	make	-C philo_three
	mv		./philo_three/philo_three ./3
123: 1 2 3


n1:
	make	-C philo_one n
n2:
	make	-C philo_two n
n3:
	make	-C philo_three n
n: n1 n2 n3

.PHONY:		all 1 2 3 n n1 n2 n3
