# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    $(MAKE)file                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:17:11 by rpinto-r          #+#    #+#              #
#    Updated: 2021/12/01 18:08:57 by rpinto-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### VARIABLES ###
CC	           = gcc
RM	           = rm -rf
CFLAGS         = -Wall -Werror -Wextra
CDEBUG         = -g3 -fsanitize=address
NORM	       = norminette
NAME           = push_swap
SRCS_INC       = ./incs
SRCS_DIR       = ./srcs
SRCS_NAME      = main.c free.c utils.c stack.c check.c push.c swap.c rotate.c reverse_rotate.c sort_small.c sort_big.c sort_utils.c sort_utils2.c
SRCS           = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS           = $(SRCS:.c=.o)
ARGS           = -58 -2 75 0 -41 -73 -29 -99 -76 -31 -22 -21 32 40 89 -5 46 1 -33 -27 55 35 95 87 47 28 -53 -68 -45 22 23 -90 2 82 -47 39 -98 31 73 -100 96 71 -54 -72 57 -88 -87 21 56 -44 -77 53 99 -32 50 -70 81 77 -18 -52 -28 -97 -15 -43 -86 -60 10 80 72 -91 97 -17 -85 -20 -26 64 -10 -66 90 67 -12 -67 -92 -30 29 -81 -34 26 -94 19 38 59 -35 -38 79 15 7 -82 6 -23

### LIBFT ###
LIBFT_INC      = ./libft
LIBFT_DIR      = ./libft
LIBFT_FLAG     = -lft

### CHECKER ###
CHECKER_DIR    = ./checkers
CHECKER_NAME   = ./checker
ifeq ($(shell uname -s), Linux)
	CHECKER_OS = ./checker_Linux
else
	CHECKER_OS = ./checker_Mac
endif

### PYTHON ###
ifeq ($(shell uname -s), Linux)
	PYTHON =/home/reek/.pyenv/versions/3.8.5/lib/python3.8
else
	PYTHON = python3
endif


### RULES ###
all: $(NAME)

.c.o:
	$(CC) -I $(SRCS_INC) -I $(LIBFT_INC) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT_FLAG) -L $(LIBFT_DIR) -o $(NAME)

dev: CFLAGS += $(CDEBUG)
dev: fclean $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT_FLAG) -L $(LIBFT_DIR) -o $(NAME)
	./$(NAME) $(ARGS)

debug:
	lldb --batch -o run $(NAME) $(ARGS)

test:
	cp $(CHECKER_DIR)/$(CHECKER_OS) $(CHECKER_NAME)
	cd push_swap_tester/ && bash tester.sh ../../push_swap 2 100
	cd push_swap_tester/ && bash tester.sh ../../push_swap 3 100
	cd push_swap_tester/ && bash tester.sh ../../push_swap 5 100
	cd push_swap_tester/ && bash tester.sh ../../push_swap 100 100
	cd push_swap_tester/ && bash tester.sh ../../push_swap 500 100

viz:
	$(PYTHON) push_swap_visualizer/push_swap_visualizer.py $(ARGS)

viz2:
	$(PYTHON) pyviz.py $$($(PYTHON) setnum.py -1000 1000 500)

norm:
	$(NORM)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(CHECKER_NAME)

re: fclean all

.PHONY: fclean clean all dev