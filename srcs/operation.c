/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:58:37 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/07 18:58:39 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_swap(t_num **list)
{
	t_num	*first;
	t_num	*second;
	t_num	*third;

	if ((*list))
	{
		if ((*list)->next)
		{
			first = (*list);
			second = (*list)->next;
			third = (*list)->next->next;
			*list = second;
			(*list)->next = first;
			(*list)->next->next = third;
		}
	}
	return (0);
}

int		ft_rotate(t_num **list)
{
	t_num	*last;
	t_num	*first;
	t_num	*lst;

	first = *list;
	lst = *list;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		last = lst;
		last->next = first;
		*list = (*list)->next;
		first->next = NULL;
	}
	return (0);
}

int		ft_rrotate(t_num **list)
{
	t_num	*last;
	t_num	*begin;
	t_num	*lst;

	if ((*list))
	{
		if ((*list)->next)
		{
			begin = *list;
			lst = *list;
			while (lst->next)
				lst = lst->next;
			while ((*list)->next->next)
				(*list) = (*list)->next;
			(*list)->next = NULL;
			last = lst;
			*list = last;
			(*list)->next = begin;
		}
	}
	return (0);
}

int		ft_push(t_num **dest, t_num **src)
{
	t_num	*top;

	if (*src)
	{
		top = *src;
		*src = (*src)->next;
		top->next = NULL;
		if (!(*dest))
			*dest = top;
		else
		{
			top->next = *dest;
			*dest = top;
		}
	}
	return (0);
}
