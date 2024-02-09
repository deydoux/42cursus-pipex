NAME				=	pipex

SOURCES				=	free_cmd.c		\
						get_path.c		\
						get_paths.c		\
						parse_cmds.c	\
						pipex.c

LIBFT_DIR			=	libft
SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
OBJECTS_DIR			=	.objects

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -MMD -I $(INCLUDE_DIR)
AR					=	ar
ARFLAGS				=	-c -r -s
RM					=	rm -rf
MKDIR				=	mkdir -p

LIBFT				=	$(LIBFT_DIR)/libft.a
OBJECTS				=	$(addprefix $(OBJECTS_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES		=	$(OBJECTS:.o=.d)

all					:	$(NAME)

-include 				$(DEPENDENCIES)

$(OBJECTS_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(LIBFT_DIR)		:
	$(MAKE) --no-print-directory -C	$@

$(LIBFT)			:	$(LIBFT_DIR)

$(NAME)				:	$(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

clean				:
	$(MAKE) --no-print-directory -C	$(LIBFT_DIR) $@
	$(RM) $(OBJECTS_DIR)

fclean				:
	$(MAKE) --no-print-directory -C	$(LIBFT_DIR) $@
	$(RM) $(OBJECTS_DIR) $(NAME)

re					:	fclean all

.PHONY				:	all bonus clean fclean re $(LIBFT_DIR)
