#!/bin/bash

echo "compiling debug"
gcc -g srcs/display_err.c srcs/main.c srcs/operations.c srcs/push.c srcs/rotate.c srcs/search.c srcs/swap.c libft/*.c -o debug
lldb ./debug
