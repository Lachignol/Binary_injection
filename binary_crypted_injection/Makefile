NAME = binary_crypted_injection
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g
MAKEFLAGS += --no-print-directory

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
RESET = \033[0m

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Include (.h)
INCLUDES = $(addprefix -I, $(INC_DIR))

# Sources
SRC = $(shell find $(SRC_DIR) -name "*.c")

# Objects
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	@echo "$(BLUE)Compiling:$(RESET) $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): echo_building_name $(OBJ)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) is ready!$(RESET)"

echo_building_name:
	@echo "$(YELLOW)Building $(NAME)...$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Clean complete!$(RESET)"

fclean:
	@echo "$(YELLOW)Full cleaning...$(RESET)"
	@echo "Cleaning exercice object files..."
	@rm -rf $(OBJ_DIR)
	@echo "Removing executable..."
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re echo_building_name 
