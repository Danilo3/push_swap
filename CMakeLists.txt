cmake_minimum_required(VERSION 3.14)
project(push_swap C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS  "-g -Wall -Wextra -Werror")

include_directories(libft/includes)
include_directories(libft/ft_printf/includes)
include_directories(includes)

# Libft with printf
file(GLOB_RECURSE LIBFT_FILES "${PROJECT_SOURCE_DIR}/libft/ft_*.c")
file(GLOB_RECURSE LIBFT_ADD_FILES "${PROJECT_SOURCE_DIR}/libft/ft_*/ft_*.c")
file(GLOB_RECURSE LIBFT_ADD_FILES "${PROJECT_SOURCE_DIR}/libft/ft_printf/srcs/*.c")
set(LIBFT_FILES ${LIBFT_FILES} ${LIBFT_ADD_FILES})
add_library(ft STATIC ${LIBFT_FILES} ${PROJECT_SOURCE_DIR}/libft/ft_gnl/get_next_line.c)

# minunit
file(GLOB_RECURSE MU_FILES "${PROJECT_SOURCE_DIR}/test/libmu/*.c")
add_library(mu STATIC ${MU_FILES})
target_include_directories(mu PUBLIC BEFORE test/libmu/)


set(SRC stack.c
        validate.c
        command.c
        swap.c
        print.c
        push.c
        rotate.c
        execute.c
        app.c
        arguments.c)

list(TRANSFORM SRC PREPEND "sources/common/")
add_executable(checker ${SRC} sources/checker/checker.c)
target_link_libraries(checker ft)

add_executable(push_swap ${SRC} sources/push_swap/push_swap.c)
target_link_libraries(push_swap ft)

add_executable(basic_test ${SRC} test/simple/basic_push_swap.c)
target_link_libraries(basic_test ft)

add_executable(fast test/fast.c)
target_link_libraries(fast ft)

function(ADD_MU_TEST EXEC_NAME PATH)
    add_executable(${EXEC_NAME}.mt ${PATH})
    target_link_libraries(${EXEC_NAME}.mt ft mu)
    add_dependencies(${EXEC_NAME}.mt mu ft)
endfunction(ADD_MU_TEST)

ADD_MU_TEST(parse_int test/additional/test_parse_int_args.c)
