cmake_minimum_required(VERSION 3.14)
project(push_swap C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS  "-Wall -Wextra -Werror")

include_directories(libft/includes)
include_directories(libft/ft_printf/includes)
include_directories(includes)

# Libft with printf
file(GLOB_RECURSE LIBFT_FILES "${PROJECT_SOURCE_DIR}/libft/ft_*.c")
file(GLOB_RECURSE LIBFT_ADD_FILES "${PROJECT_SOURCE_DIR}/libft/ft_*/ft_*.c")
file(GLOB_RECURSE LIBFT_ADD_FILES "${PROJECT_SOURCE_DIR}/libft/ft_printf/srcs/*.c")
set(LIBFT_FILES ${LIBFT_FILES} ${LIBFT_ADD_FILES})
add_library(ft STATIC ${LIBFT_FILES} ${PROJECT_SOURCE_DIR}/libft/ft_gnl/get_next_line.c)


add_executable(push_swap sources/push_swap.c)
target_link_libraries(push_swap ft)

set(SRC sources/stack.c
        sources/validate.c
        sources/command.c
        sources/basic_ops.c
        sources/basic_ops.c
        sources/solution.c
        sources/rotate_ops.c
        sources/execute.c)

add_executable(checker ${SRC} sources/checker.c)
target_link_libraries(checker ft)

