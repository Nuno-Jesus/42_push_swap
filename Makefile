#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COLORS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CC = cc
RM = rm -f
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CFLAGS		= -Wall -Wextra -Werror 
MKFLAGS		= --no-print-directory
LIBFT		= -L ./libft -lft
GNL			= -L ./get_next_line -lgnl

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS		= includes 
SRCS		= srcs
SRCS_BONUS	= srcs_bonus
LIBFT_PATH	= libft
GNL_PATH	= get_next_line

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
OBJS			= state.o stack.o operations_1.o operations_2.o
OBJS_BONUS		= 
NAME			= push_swap
NAME_BONUS		= checker
TARGET			= $(addprefix $(SRCS)/, $(OBJS))
TARGET_BONUS	= $(addprefix $(SRCS_BONUS)/, $(OBJS_BONUS))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(TARGET)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -C $(LIBFT_PATH)
		
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) main.c $(TARGET) $(LIBFT) -o $(NAME) -I $(DEPS)
	
	echo "$(GREEN)Done.$(RESET)"
	
%.o : %.c 
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	make clean $(MKFLAGS) -C $(LIBFT_PATH)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)*/*.o$(RESET)"
	$(RM) $(TARGET)

fclean: clean
	make fclean $(MKFLAGS) -C $(LIBFT_PATH)
	echo "[$(RED) Deleted $(RESET)] $(GREEN) $(NAME) $(RESET)"
	$(RM) $(NAME) 

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(TARGET_BONUS)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -C $(LIBFT_PATH)
		
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) main.c $(TARGET_BONUS) $(LIBFT) -o $(NAME) -I $(DEPS)
	
	echo "$(GREEN)Done.$(RESET)"

.SILENT:
re: fclean all

