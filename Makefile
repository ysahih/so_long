NAME = so_long
HDR = so_long.h
SRCS = so_long.c \
textures/map_checks/map_utils.c textures/map_checks/map_info.c textures/map_checks/bfs.c \
textures/map_checks/bfs_utils1.c textures/map_checks/bfs_utils2.c textures/map_checks/other_utils.c\
textures/utils/gnl.c textures/utils/mlx_utils.c textures/utils/utils.c \
textures/game_logic/move.c textures/game_logic/move_utils.c \

OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all