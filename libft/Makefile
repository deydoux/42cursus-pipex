NAME				=	libft.a

SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
OBJECTS_DIR			=	.objects

SOURCES				=	ft_printf/ft_printf.c		\
						ft_printf/get_flags.c		\
						ft_printf/print_char.c		\
						ft_printf/print_ptr.c		\
						ft_printf/print_signed.c	\
						ft_printf/print_str.c		\
						ft_printf/print_unsigned.c	\
						get_next_line.c				\
						int/ft_abs.c				\
						int/ft_isalnum.c			\
						int/ft_isalpha.c			\
						int/ft_isascii.c			\
						int/ft_isblank.c			\
						int/ft_iscntrl.c			\
						int/ft_isdigit.c			\
						int/ft_isgraph.c			\
						int/ft_islower.c			\
						int/ft_isprint.c			\
						int/ft_ispunct.c			\
						int/ft_isspace.c			\
						int/ft_isupper.c			\
						int/ft_isxdigit.c			\
						int/ft_tolower.c			\
						int/ft_toupper.c			\
						lst/ft_lstadd_back.c		\
						lst/ft_lstadd_front.c		\
						lst/ft_lstclear.c			\
						lst/ft_lstdelone.c			\
						lst/ft_lstiter.c			\
						lst/ft_lstlast.c			\
						lst/ft_lstmap.c				\
						lst/ft_lstnew.c				\
						lst/ft_lstsize.c			\
						mem/ft_bzero.c				\
						mem/ft_calloc.c				\
						mem/ft_memchr.c				\
						mem/ft_memcmp.c				\
						mem/ft_memcpy.c				\
						mem/ft_memmove.c			\
						mem/ft_memset.c				\
						put/ft_putchar_fd.c			\
						put/ft_putendl_fd.c			\
						put/ft_putnbr_fd.c			\
						put/ft_putstr_fd.c			\
						str/ft_atoi.c				\
						str/ft_itoa.c				\
						str/ft_split.c				\
						str/ft_strchr.c				\
						str/ft_strcmp.c				\
						str/ft_strdup.c				\
						str/ft_striteri.c			\
						str/ft_strjoin.c			\
						str/ft_strlcat.c			\
						str/ft_strlcpy.c			\
						str/ft_strlen.c				\
						str/ft_strmapi.c			\
						str/ft_strncmp.c			\
						str/ft_strnstr.c			\
						str/ft_strrchr.c			\
						str/ft_strtrim.c			\
						str/ft_substr.c

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -MMD -I $(INCLUDE_DIR)
AR					=	ar
ARFLAGS				=	-c -r -s
RM					=	rm -rf
MKDIR				=	mkdir -p

OBJECTS				=	$(addprefix $(OBJECTS_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES		=	$(addprefix $(OBJECTS_DIR)/,$(SOURCES:.c=.d))

all					:	$(NAME)

-include 				$(DEPENDENCIES)

$(OBJECTS_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(NAME)				:	$(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

clean				:
	$(RM) $(OBJECTS_DIR)

fclean				:
	$(RM) $(OBJECTS_DIR) $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
