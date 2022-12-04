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
TARGET = 
NAME = push_swap
PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a

#! Rules

all: $(NAME)

$(NAME): $(TARGET)
	@echo "[${CYAN}Compiling${RESET}] ${GREEN}ft_printf${RESET}"
	@make $(MKFLAGS) -C ft_printf
	$(CC) $(CFLAGS) $(TARGET) $(PRINTF) $(LIBFT) -o $(NAME) -I $(DEPS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	@echo "[${CYAN}Cleaning${RESET}] ${GREEN}push_swap *.o${RESET}"
	@make clean $(MKFLAGS) -C ft_printf
	@$(RM) $(TARGET)

fclean: clean
	@make fclean $(MKFLAGS) -C ft_printf
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

bonus: all

re: fclean all
