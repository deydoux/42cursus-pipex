NAME				=	pipex
BONUS_NAME			=	pipex_bonus

SOURCES				=	exec_cmds.c		\
						free_cmd.c		\
						get_path.c		\
						parse_cmds.c	\
						parse_files.c	\
						pipex.c			\
						safe_close.c

LIBFT_DIR			=	libft
SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
OBJECTS_DIR			=	.objects
BONUS_OBJECTS_DIR	=	$(OBJECTS_DIR)/bonus

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -MMD -I $(INCLUDE_DIR)
BONUS_CFLAGS		=	$(CFLAGS) -D BONUS=true
AR					=	ar
ARFLAGS				=	-c -r -s
RM					=	rm -rf
MKDIR				=	mkdir -p

LIBFT				=	$(LIBFT_DIR)/libft.a
OBJECTS				=	$(addprefix $(OBJECTS_DIR)/,$(SOURCES:.c=.o))
BONUS_OBJECTS		=	$(addprefix $(BONUS_OBJECTS_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES		=	$(OBJECTS:.o=.d) $(BONUS_OBJECTS:.o=.d)

all					:	$(NAME) bonus

bonus				:	$(BONUS_NAME)

-include 				$(DEPENDENCIES)

$(BONUS_OBJECTS_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(BONUS_CFLAGS) -o $@ -c	$<

$(OBJECTS_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(LIBFT_DIR)		:
	$(MAKE) --no-print-directory -C	$@

$(LIBFT)			:	$(LIBFT_DIR)

$(NAME)				:	$(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME)		:	$(BONUS_OBJECTS) $(LIBFT)
	$(CC) $(BONUS_CFLAGS) -o $@ $^

clean				:
	$(MAKE) --no-print-directory -C	$(LIBFT_DIR) $@
	$(RM) $(OBJECTS_DIR)

fclean				:
	$(MAKE) --no-print-directory -C	$(LIBFT_DIR) $@
	$(RM) $(OBJECTS_DIR) $(NAME) $(BONUS_NAME)

re					:	fclean all

.PHONY				:	all bonus clean fclean re $(LIBFT_DIR)
