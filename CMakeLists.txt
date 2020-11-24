cmake_minimum_required(VERSION 3.17)
project(Philosophers C)

set(CMAKE_C_STANDARD 99)
#[[set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )]]
add_executable(Philosophers
        #philo_one
#[[        philo_one/philosophers.c
        philo_one/philosophers.h
        philo_one/ft_atoi.c
        philo_one/ft_itoa.c
        philo_one/ft_str_for_msg.c
        philo_one/defines.h
        philo_one/ft_join_3_ptr.c
        philo_one/ft_start.c
        philo_one/ft_utils.c]]

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
        philo_two/ft_free_xxx.c)