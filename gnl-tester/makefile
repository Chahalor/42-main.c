NAME	= gnl-tester

DIRMAIN	= ./
DIRGNL	= ../
OBJDIR	= .obj

MAIN			= main.c
MAINBONUS		= main_bonus.c
GNL				= get_next_line.c get_next_line_utils.c
BONUS			= get_next_line_bonus.c get_next_line_utils_bonus.c
HEADERGNL		= get_next_line.h
HEADERGNLBNS	= get_next_line_bonus.h

HEADER		= get_next_line.h
HEADERBONUS	= get_next_line_bonus.h

OBJSMAIN	= $(addprefix $(OBJDIR)/, $(MAIN:.c=.o))
OBJSMAINBNS	= $(addprefix $(OBJDIR)/, $(MAINBONUS:.c=.o))
OBJSGNL		= $(addprefix $(OBJDIR)/, $(GNL:.c=.o))
OBJSBONUS	= $(addprefix $(OBJDIR)/, $(BONUS:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJSMAIN) $(OBJSGNL)
	$(CC) $(CFLAGS) -I $(DIRGNL)/$(HEADERGNL) $(OBJSMAIN) $(OBJSGNL) -o $(NAME)
	./$(NAME)


bonus: $(OBJSMAINBNS) $(OBJSBONUS)
	$(CC) $(CFLAGS) -I $(DIRGNL)/$(HEADERBONUS) $(OBJSMAINBNS) $(OBJSBONUS) -o $(NAME)
	./$(NAME)

$(OBJDIR)/%.o: $(DIRMAIN)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(DIRGNL) -c $< -o $@

$(OBJDIR)/%.o: $(DIRGNL)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I $(DIRGNL) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
