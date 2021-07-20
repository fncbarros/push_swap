#!/bin/bash

echo "compiling debug"
gcc -g srcs/utils.c srcs/main.c srcs/operations.c srcs/push.c srcs/rotate.c srcs/swap.c srcs/push_swap.c libft/*.c -o debug
lldb ./debug