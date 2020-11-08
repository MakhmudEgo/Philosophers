cmake_minimum_required(VERSION 3.17)
project(Philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(Philosophers
        philo_one/philosophers.c
        philo_one/philosophers.h
        philo_one/ft_atoi.c
        philo_one/ft_putnbr_fd.c
        philo_one/ft_strlen.c

#        test.c
#        ggg.c
        )