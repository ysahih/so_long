#ifndef SO_LONG_H 
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
#include <stdbool.h>
#include <mlx.h>

#define SIZE 64

typedef struct s_count
{
	int p;
	int e;
	int c;
}t_count;

typedef struct s_point {
	int x;
	int y;
	int	row;
	int	col;
}t_point;

typedef struct s_data
{
	char **map;
	int row;
	int col;
	int collectibles;
	t_point p;
	t_point new_pos;
	void *floor_img;
	void *wall_img;
	void *player_img;
	void *exit_img;
	void *cll_img;
	void *mlx_ptr;
	void *mlx_wind;
}t_data;


typedef struct s_queue
{
	int x;
    int y;
	struct s_queue* next;
} t_queue;


//game play
int		key_hook(int keycode, t_data *info);
void	move_player(t_data *info);
bool	move_right(t_data *info);
bool	move_left(t_data *info);
bool	move_up(t_data *info);
bool	move_down(t_data *info);
bool 	possible_tomove(t_data *info);
void	ft_putnbr(int n);


//rendring
void	put_image_to_window(t_data *info, int row, int col);
void	rendering(t_data *info);

//utils 
void	ft_free(char **s);


//map checker
bool map_requesties(char **map);
bool components(char **map);
bool rectangular(char **map, int a);
bool walls_serounded(char **map, int a);
bool found_elmnt(char c);
//map info
int	count_c(char **map);
int calculate_size(char *file);
t_point find_player(char **map);
char** read_map(char *s, int *row);
int count_items(char **s);

//path finding 
bool bfs(t_point p, char **map , int row, int col);
void enqueue(t_queue **lst, t_point p);
void dequeue(t_queue **lst);
bool queueisempty(t_queue *lst);
void	ft_lstadd_back(t_queue **lst, t_queue *new);
t_queue	*ft_lstlast(t_queue *lst);

//gnl
char *gnl(int fd);
char *join(char *s, char c);

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*after_newline(char *line);
int		check_newline(char *line);

#endif
