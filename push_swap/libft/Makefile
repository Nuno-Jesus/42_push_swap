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

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS		= ../includes
SRCS		= .

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
OBJS			= ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
					ft_isprint.o ft_itoa.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o \
					ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o \
					ft_strdup.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o \
					ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o
OBJS_BONUS		= ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o \
					ft_lstdelone.o ft_lstiter.o ft_lstlast.o \
					ft_lstmap.o ft_lstnew.o ft_lstsize.o
NAME			= libft.a
TARGET			= $(addprefix $(SRCS)/, $(OBJS))
TARGET_BONUS	= $(addprefix $(SRCS_BONUS)/, $(OBJS_BONUS))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(TARGET)
	$(AR) $(NAME) $^
	
%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	$(RM) $(TARGET)

fclean: clean
	$(RM) $(NAME) 

bonus: $(TARGET_BONUS)
	$(AR) $(NAME) $^
	
.SILENT:
re: fclean all

