#ifndef SO_LONG_H 
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
#include <stdbool.h>


typedef struct s_point {
	int x;
	int y;
}t_point;

typedef struct s_data
{
	char **map;
	int row;
	int col;
	t_point p;


}t_data;


typedef struct s_queue
{
	int x;
    int y;
	struct s_queue* next;
} t_queue;




//map checker
bool map_requesties(char **map);
bool components(char **map);
bool rectangular(char **map, int a);
bool walls_serounded(char **map, int a);
bool found_elmnt(char c);
//map info
int calculate_size(char *file);
t_point find_player(char **map);
char** read_map(int *a);
int count_items(char **s);

//path finding 
bool bfs(t_point p, char **map , int row, int col);
void enqueue(t_queue **lst, t_point p);
void dequeue(t_queue **lst);
bool queueisempty(t_queue *lst);
void	ft_lstadd_back(t_queue **lst, t_queue *new);
t_queue	*ft_lstlast(t_queue *lst);

//gnl
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*after_newline(char *line);
int		check_newline(char *line);

#endif
