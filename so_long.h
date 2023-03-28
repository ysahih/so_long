/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:00:27 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/28 17:55:58 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include <mlx.h>

# define SIZE 64

typedef struct s_count
{
	int	p;
	int	e;
	int	c;
}	t_count;

typedef struct s_point {
	int	x;
	int	y;
	int	row;
	int	col;
}	t_point;

typedef struct s_data
{
	char	**map;
	int		row;
	int		col;
	int		collectibles;
	t_point	p;
	t_point	new_pos;
	void	*floor_img;
	void	*wall_img;
	void	*player_img;
	void	*exit_img;
	void	*cll_img;
	void	*mlx_ptr;
	void	*mlx_wind;
}	t_data;

typedef struct s_queue
{
	int				x;
	int				y;
	struct s_queue	*next;
}	t_queue;

//game play
int		key_hook(int keycode, t_data *info);
void	move_player(t_data *info);
bool	move_right(t_data *info);
bool	move_left(t_data *info);
bool	move_up(t_data *info);
bool	move_down(t_data *info);
bool	possible_tomove(t_data *info);
void	ft_putnbr(int n);
//rendring
void	put_image_to_window(t_data *info, int row, int col);
void	rendering(t_data *info);
//utils
void	ft_free(char **s);
int		ft_strlen(char *s);
int		cross_hook(t_data *info);
void	check_map_name(char *s);
void	ft_exit(void);
bool	check_and_return(t_count c);
t_count	init_c(void);
//map checker
bool	map_requesties(char **map);
bool	components(char **map);
bool	rectangular(char **map, int a);
bool	walls_serounded(char **map, int a);
bool	found_elmnt(char c);
//map info
int		count_c(char **map);
int		calculate_size(char *file);
t_point	find_player(char **map);
char	**read_map(char *s, int *row);
int		count_items(char **s);
//bfs utils 1 
bool	bfs(t_point p, char **map, int row, int col);
void	enqueue(t_queue **lst, t_point p);
void	dequeue(t_queue **lst);
bool	queueisempty(t_queue *lst);
void	ft_lstadd_back(t_queue **lst, t_queue *new);
t_queue	*ft_lstlast(t_queue *lst);
//bfs utils 2
char	**init_bfs_vars(t_point *p, int *count, t_queue **queue);
char	**get_visited(int row, int col);
void	free_visited(char **s, int row);
bool	path_found(t_queue *q, char **v, int row);
bool	no_path_found(char **visited, int row, t_queue *q);
bool	path_found(t_queue *q, char **v, int row);
//gnl
char	*gnl(int fd);
char	*join(char *s, char c);

#endif