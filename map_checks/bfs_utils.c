#include "../so_long.h"

t_queue	*ft_lstlast(t_queue *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_queue **lst, t_queue *new)
{
	t_queue	*tmp;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

void	enqueue(t_queue **lst, t_point p)
{
	t_queue	*list;

	list = malloc(sizeof(t_queue));
	if(!list)
		return ; 
	list->x = p.x;
	list->y = p.y;
	list->next  = 0x0;
	ft_lstadd_back(lst,list);
}

void	dequeue(t_queue **lst)
{
	t_queue *tmp = *lst;
	if (*lst == NULL)
		return ;
	else 
		*lst = (*lst)->next;
	free(tmp);
}

bool	queueisempty(t_queue *lst)
{
	if (lst == NULL)
		return (true);
	return (false);
}