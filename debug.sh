#!/bin/bash

echo "compiling debug"
gcc -g srcs/utils.c srcs/main.c srcs/operations.c srcs/push.c srcs/sort_array.c srcs/rotate.c srcs/swap.c srcs/sort_small.c srcs/d_list.c srcs/radix.c srcs/err_handling.c libft/*.c -o debug
lldb ./debug
