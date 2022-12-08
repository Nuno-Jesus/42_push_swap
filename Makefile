#! Colors
RESET = \033[0m       # Text Reset
BLACK = \033[1;30m       # Black
RED = \033[1;31m         # Red
GREEN = \033[1;32m       # Green
YELLOW = \033[1;33m      # Yellow
BLUE = \033[1;34m       # Blue
PURPLE = \033[1;35m     # Purple
CYAN = \033[1;36m        # Cyan
WHITE = \033[1;37m       # White

#! Commands
CC = cc
RM = rm -f
AR = ar -rc

#! Flags
CFLAGS = -Wall -Wextra -Werror
MKFLAGS = --no-print-directory

#! Folders
DEPS = includes
SRCS = .

#! Files
TARGET = main.o srcs/stack.o srcs/operations_1.o srcs/operations_2.o srcs/state.o
NAME = push_swap
PRINTF = ft_printf
LIBFT = libft

#! Rules

all: $(NAME)

$(NAME): $(TARGET)
	@echo "[${CYAN}Compiling${RESET}] ${GREEN}ft_printf${RESET}"
	@make bonus $(MKFLAGS) -C $(LIBFT)
	$(CC) $(CFLAGS) $(TARGET) $(LIBFT)/libft.a -o $(NAME) -I $(DEPS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	@echo "[${CYAN}Cleaning${RESET}] ${GREEN}*.o${RESET}"
	@make clean $(MKFLAGS) -C $(LIBFT)
	@$(RM) $(TARGET)

fclean: clean
	@make fclean $(MKFLAGS) -C $(LIBFT)
	@$(RM) $(NAME)

bonus: all

re: fclean all

