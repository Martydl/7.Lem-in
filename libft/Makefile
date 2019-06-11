NAME		= libft.a

#Sources

LIB_SRCS_NAME	=	conv/ft_atoi.c \
					conv/ft_atol.c \
					conv/ft_convert_base.c \
					conv/ft_itoa.c \
					conv/ft_ltoa.c \
					conv/ft_lutoa_base.c \
\
					is/ft_isalnum.c \
					is/ft_isalpha.c \
					is/ft_isascii.c \
					is/ft_isblank.c \
					is/ft_iscntrl.c \
					is/ft_isdigit.c \
					is/ft_isgraph.c \
					is/ft_isint.c \
					is/ft_islower.c \
					is/ft_isprint.c \
					is/ft_isspace.c \
					is/ft_isupper.c \
					is/ft_isxdigit.c \
					is/ft_str_is_alpha.c \
					is/ft_str_is_lowercase.c \
					is/ft_str_is_numeric.c \
					is/ft_str_is_printable.c \
					is/ft_str_is_uppercase.c \
\
					lst/ft_lstadd.c \
					lst/ft_lstdel.c \
					lst/ft_lstdelone.c \
					lst/ft_lstiter.c \
					lst/ft_lstmap.c \
					lst/ft_lstnew.c \
\
					mem/ft_memalloc.c \
					mem/ft_memccpy.c \
					mem/ft_memchr.c \
					mem/ft_memcmp.c \
					mem/ft_memcpy.c \
					mem/ft_memdel.c \
					mem/ft_memmove.c \
					mem/ft_memset.c \
\
					print/ft_putchar_fd.c \
					print/ft_putchar.c \
					print/ft_putendl_fd.c \
					print/ft_putendl.c \
					print/ft_putnbr_fd.c \
					print/ft_putnbr.c \
					print/ft_putstr_fd.c \
					print/ft_putstr.c \
\
					str/ft_bzero.c \
					str/ft_strcat.c \
					str/ft_strchr.c \
					str/ft_strclr.c \
					str/ft_strcmp.c \
					str/ft_strcpy.c \
					str/ft_strdel.c \
					str/ft_strdup.c \
					str/ft_strequ.c \
					str/ft_striter.c \
					str/ft_striteri.c \
					str/ft_strjfree.c \
					str/ft_strjoin.c \
					str/ft_strlcat.c \
					str/ft_strlen.c \
					str/ft_strlowcase.c \
					str/ft_strmap.c \
					str/ft_strmapi.c \
					str/ft_strncat.c \
					str/ft_strncmp.c \
					str/ft_strncpy.c \
					str/ft_strndup.c \
					str/ft_strnequ.c \
					str/ft_strnew.c \
					str/ft_strnstr.c \
					str/ft_strrchr.c \
					str/ft_strsplit.c \
					str/ft_strstr.c \
					str/ft_strsub.c \
					str/ft_strtrim.c \
					str/ft_strupcase.c \
					str/ft_tolower.c \
					str/ft_toupper.c \
\
					gnl/get_next_line.c

PRINTF_SRCS_NAME =	ft_convb.c \
					ft_convc.c \
					ft_convd.c \
					ft_convert.c \
					ft_convf.c \
					ft_convg.c \
					ft_convi.c \
					ft_convmb.c \
					ft_convmf.c \
					ft_convmg.c \
					ft_convmx.c \
					ft_convo.c \
					ft_convp.c \
					ft_convperct.c \
					ft_convs.c \
					ft_convu.c \
					ft_convx.c\
					ft_error.c \
					ft_float.c \
					ft_float2.c\
					ft_parse.c \
					ft_printf.c \
					ft_putstrplus.c \
					ft_reset.c \
					ft_stokpar.c \
					ft_structfiller.c \
					ft_structfiller2.c

INCS_NAME		=	libft.h

# Directories

LIB_SRCS_DIR	=	./srcs/libc/
LIB_OBJS_DIR	=	./objs/libc/
PRINTF_SRCS_DIR	=	./srcs/ft_printf/
PRINTF_OBJS_DIR	=	./objs/ft_printf/
INCS_DIR		=	./includes/

# Files

LIB_SRCS		=	$(addprefix $(LIB_SRCS_DIR), $(LIB_SRCS_NAME))
LIB_OBJS		=	$(patsubst $(LIB_SRCS_DIR)%.c, $(LIB_OBJS_DIR)%.o, $(LIB_SRCS))
PRINTF_SRCS		=	$(addprefix $(PRINTF_SRCS_DIR), $(PRINTF_SRCS_NAME))
PRINTF_OBJS		=	$(patsubst $(PRINTF_SRCS_DIR)%.c, $(PRINTF_OBJS_DIR)%.o, $(PRINTF_SRCS))
INCS			=	$(addprefix $(INCS_DIR), $(INCS_NAME))

# Compilation

CC			=	gcc
CPPFLAGS	=	-I $(INCS_DIR)
CFLAGS		=	-Wall -Wextra -Werror -g $(CPPFLAGS)

all: $(NAME)

$(NAME): $(LIB_OBJS) $(PRINTF_OBJS)
	@ar rc $(NAME) $(LIB_OBJS) $(PRINTF_OBJS)
	@ranlib $(NAME)
	@echo Libft OK

$(LIB_OBJS_DIR)%.o:  $(LIB_SRCS_DIR)%.c $(INCS)
	@mkdir -p ./objs/libc/conv ./objs/libc/gnl ./objs/libc/is ./objs/libc/lst ./objs/libc/mem ./objs/libc/print ./objs/libc/str
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(PRINTF_OBJS_DIR)%.o: $(PRINTF_SRCS_DIR)%.c $(INCS)
	@mkdir -p $(PRINTF_OBJS_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)
	@echo Libft fclean OK

re: fclean all

.PHONY: all clean fclean re
