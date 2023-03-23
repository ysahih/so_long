NAME = so_long
SRCS = so_long.c \
map_checks/map_utils.c map_checks/map_info.c map_checks/bfs.c map_checks/bfs_utils.c \
utils/gnl_utils.c utils/gnl.c mlx_utils.c \

OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all