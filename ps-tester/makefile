# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 12:21:31 by nduvoid           #+#    #+#              #
#    Updated: 2024/12/06 14:27:52 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	checker

CC =			cc 
CFLAGS =		-Wall -Wextra -Werror
DEBUGFLAGS =	-g3 -fsanitize=address
RM =			rm -rf

SRC_DIR =	src
OBJ_DIR =	.obj
LIBFT_DIR =	libft

SRC =	checker.c \
		command.c \
		command2.c \
		command3.c \
		utils.c

LIBFT =	ft_atoi.c \
		ft_calloc.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_strncmp.c

OBJ =	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT_OBJ =	$(addprefix $(OBJ_DIR)/, $(LIBFT:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean 
	@$(RM) $(NAME)

re: fclean all

debug: $(OBJ) $(LIBFT_OBJ)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJ) $(LIBFT_OBJ) -o $(NAME)

.PHONY: all clean fclean re