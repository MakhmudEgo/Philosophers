cmake_minimum_required(VERSION 3.17)
project(Philosophers C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra" )
add_executable(philo_one
        #philo_one
        philo_one/philosophers.c
        philo_one/philosophers.h
        philo_one/ft_atoi.c
        philo_one/ft_itoa.c
        philo_one/ft_str_for_msg.c
        philo_one/defines.h
        philo_one/ft_join_3_ptr.c
        philo_one/ft_start.c
        philo_one/ft_utils.c
        )
add_executable(philo_two
        #philo_two
        philo_two/philosophers.c
        philo_two/philosophers.h
        philo_two/ft_atoi.c
        philo_two/ft_itoa.c
        philo_two/ft_str_for_msg.c
        philo_two/defines.h
        philo_two/ft_join_3_ptr.c
        philo_two/ft_start.c
        philo_two/ft_utils.c
        philo_two/ft_free_xxx.c
        )
add_executable(philo_three
        #philo_three
        philo_three/philosophers.c
        philo_three/philosophers.h
        philo_three/ft_atoi.c
        philo_three/ft_itoa.c
        philo_three/ft_str_for_msg.c
        philo_three/defines.h
        philo_three/ft_join_3_ptr.c
        philo_three/ft_start.c
        philo_three/ft_utils.c
        philo_three/ft_free_xxx.c
        )