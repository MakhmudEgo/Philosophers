cmake_minimum_required(VERSION 3.17)
project(Philosophers C)

set(CMAKE_C_STANDARD 99)
#[[set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )]]
add_executable(Philosophers
        philo_one/philosophers.c
        philo_one/philosophers.h
        philo_one/ft_atoi.c
        philo_one/ft_itoa.c
        philo_one/ft_str_for_msg.c
        philo_one/defines.h
        philo_one/ft_join_3_ptr.c philo_one/ft_start.c philo_one/ft_utils.c)