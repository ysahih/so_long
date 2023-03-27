/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:34:33 by ysahih            #+#    #+#             */
/*   Updated: 2023/03/27 17:34:34 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_count	init_c(void)
{
	t_count	c;

	c.c = 0;
	c.e = 0;
	c.p = 0;
	return (c);
}

bool	check_and_return(t_count c)
{
	if (c.e != 1 || c.p != 1)
		return (false);
	else if (c.c == 0)
		return (false);
	return (true);
}
