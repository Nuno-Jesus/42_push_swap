#! Colors
RESET 	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE 	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#! Commands
CC 		= cc
RM 		= rm -f
AR 		= ar -rcs

#! Flags
CFLAGS 	= -Wall -Wextra -Werror
MKFLAGS = --no-print-directory

#! Folders
DEPS 	= includes
SRCS 	= srcs
OBJS 	= .
LIBFT 	= libft

#! Files
TARGET 	= main.o stack.o operations_1.o operations_2.o state.o
NAME 	= push_swap
OBJECTS = $(addprefix $(OBJS)/, $(TARGET))

#! Rules

all: $(NAME)

$(NAME): $(TARGET)
	@make bonus $(MKFLAGS) -C $(LIBFT)
	@echo "[$(CYAN)Compiled$(RESET)] $(GREEN)libft$(RESET)"

	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT)/libft.a -o $(NAME) -I $(DEPS)
	@echo "[$(CYAN)Linked$(RESET)] $(GREEN)push_swap$(RESET)"

%.o : $(SRCS)/%.c 
	@mkdir -p $(OBJS)
	@$(CC) $(CFLAGS) -c $< -o $(OBJS)/$@ -I $(DEPS)
	@echo "[$(CYAN)Compiled$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"

clean:
	@make clean $(MKFLAGS) -C $(LIBFT)
	@$(RM) $(OBJECTS)
	@echo "[$(CYAN)Cleaned$(RESET)] $(GREEN)*.o$(RESET)"

fclean: clean
	@make fclean $(MKFLAGS) -C $(LIBFT)
	@$(RM) $(NAME)
	@echo "[$(CYAN)Cleaned$(RESET)] $(GREEN)$(NAME)$(RESET)"

bonus: all

re: fclean all

