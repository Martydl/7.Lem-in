NAME = lem-in

# Sources

SRCS_NAME =	lem_in.c \
			ft_read.c \
			ft_room.c \
			ft_matrix.c \
			ft_bfs.c \
			ft_getpaths.c \
			ft_bestpath.c \
			ft_doit.c \
			ft_display.c \
			ft_free.c \
			tools_bfs.c \
			tools_is.c \
			tools_path.c \
			tools_lst.c \
			tools_other.c

INCS_NAME	=	lem_in.h

LIB_NAME	=	libft.a

# Directories

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INCS_DIR	=	./includes/
LIB_DIR		=	./libft/

# Files

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
INCS		=	$(addprefix $(INCS_DIR), $(INCS_NAME))
LIB			=	$(addprefix $(LIB_DIR), $(LIB_NAME))

# Compilation

CC			=	gcc
CPPFLAGS	=	-I $(INCS_DIR)
LIBH		=	-I $(LIB_DIR)includes/
CFLAGS		=	-Wall -Wextra -Werror -g $(CPPFLAGS) $(LIBH)

all: $(NAME)

$(LIB):
	@make -j -sC $(LIB_DIR)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(OBJS) $(LIB) -o $(NAME)
	@echo lem-in OK

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCS)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

librm:
	@make -sC libft fclean

clean:
	@rm -rf $(OBJS_DIR)
	@make -C libft clean

fclean: librm clean
	@rm -f $(NAME)
	@echo lem-in fclean OK

re: fclean all

.PHONY: all librm clean fclean re
