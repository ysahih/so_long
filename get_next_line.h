/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:34:22 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/16 20:16:29 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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


// typedef struct list
// {
// 	void *content;
// 	struct list* next;
// } list;
    
typedef struct node
{
	int x;
    int y;
	struct node* next;
} node;

typedef struct point {
	int x;
	int y;
}point;

bool found_elmnt(char c);
bool bfs(point p, char **map , int i);
int count_items(char **s);
void dequeue(node *lst);
void	ft_lstadd_back(node **lst, node *new);
node	*ft_lstlast(node *lst);
void enqueue(node **lst, point p);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*after_newline(char *line);
int		check_newline(char *line);

#endif
