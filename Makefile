NAME = so_long
SRCS = so_long.c \
map_checks/map_utils.c map_checks/map_info.c map_checks/bfs.c map_checks/bfs_utils1.c map_checks/bfs_utils2.c map_checks/other_utils.c\
utils/gnl.c utils/mlx_utils.c utils/utils.c \
game_logic/move.c game_logic/move_utils.c \

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