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
	rm -rfv philo_one/*.o
	rm -rfv philo_one/philo_one
	rm -rfv philo_two/*.o
	rm -rfv philo_two/philo_two
	rm -rfv philo_three/*.o
	rm -rfv philo_three/philo_three

.PHONY:		all
