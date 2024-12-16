#			-->|   Files to Compile   |<--
FILES		=		ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint			\
					ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp		\
					ft_toupper ft_tolower ft_strchr ft_strrchr ft_strnstr			\
					ft_strlen ft_strncmp ft_strlcpy ft_strlcat ft_atoi ft_itoa		\
					ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split	\
					ft_strmapi ft_striteri											\
					ft_putchar_fd ft_putstr_fd ft_putnbr_fd ft_putendl_fd
FILES_B		=		ft_lstnew ft_lstadd_front ft_lstadd_back ft_lstsize ft_lstlast	\
					ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

#			-->|   Titles   |<--
HEAD		=		"42 Library"
HEAD_B		=		"42 Library Bonus"
NAME		=		libft.a

#			-->|   Command Definitions   |<--
INC_DIR		=		./
SRC_DIR		=		./
OBJ_DIR		=		obj/

SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES, FILES_B)))
OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
OBJ_B		=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_B)))

FLAGS		=		-Wall -Wextra -Werror
COMPILE		=		@cc $(FLAGS) -I $(INC_DIR) -c $< -o $@
RMV			=		@rm -rf $(OBJ_DIR)
AR			=		@ar -rcs $(NAME) $(OBJ)
AR_B		=		@ar -rcs $(NAME) $(OBJ_B)

EXE			=		@cc -I $(INC_DIR) -o exe .main.c $(NAME) && ./exe other && rm -f exe

#			-->|   Colors & Messages   |<--
START		=		1
BONUS		=		1

GRAY		=		\033[0;30m
GREEN		=		\033[0;32m
YELLOW		=		\033[0;33m
BLUE		=		\033[0;34m
MAGENTA		=		\033[0;35m
CYAN		=		\033[0;36m
WHITE		=		\033[0;37m
DEF			=		\033[0;39m

BGREEN		=		\033[1;32m
BYELLOW		=		\033[1;33m
BBLUE		=		\033[1;34m
BMAGENTA	=		\033[1;35m
BCYAN		=		\033[1;36m

T_CREATING	=		@echo "$(GRAY)-->|	$(BBLUE)Creating $(HEAD) at $(NAME) $(GRAY)...\n"
T_CREATING_B=		@echo "$(GRAY)-->|	$(BBLUE)Creating $(HEAD_B) at $(NAME) $(GRAY)...\n"
T_BUILDING	=		@echo "	$(GRAY)... $(BYELLOW)Building $(NAME) $(GRAY)... \n"
T_COMPILING	=		@echo "	$(GRAY)... $(YELLOW)Compiling $< $(GRAY)..."
T_REMOVE_O	=		@echo "$(MAGENTA)$(HEAD): Objects Removed!$(DEF)\n"
T_REMOVE_A	=		@echo "$(BMAGENTA)$(HEAD): All Files Removed!$(DEF)\n"
T_COMPILED	=		@echo "\n$(BGREEN)	     $(HEAD) Compiled!   $(GRAY)|<--$(DEF)\n"
T_EXECUTING	=		@echo "\n$(GRAY)-->|	$(BLUE)Executing: $(BCYAN)$(NAME) - main.c $(BLUE)at $(WHITE)exe $(GRAY)...$(DEF)"
T_EXECUTED	=		@echo "$(GRAY)	...$(BGREEN)Execution Ended!   $(GRAY)|<--$(DEF)\n"

#			-->|   Rules   |<--
.PHONY: all bonus clean fclean re exe

all: $(START) $(NAME)
	$(T_COMPILED)

bonus: $(START) $(NAME) $(OBJ_B)
	$(AR_B)
	$(T_COMPILED)

clean:
	$(RMV)
	$(T_REMOVE_O)

fclean:
	$(RMV) $(NAME)
	$(T_REMOVE_A)

re: fclean all

exe: re
	$(T_EXECUTING)
	$(EXE)
	$(T_EXECUTED)

#			-->|   File Dependencies   |<--
$(START):
	$(T_CREATING)
	$(T_BUILDING)

$(BONUS):
	$(T_CREATING_B)
	$(T_BUILDING)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(T_COMPILING)
	$(COMPILE)

$(NAME): $(OBJ)
	$(AR)
