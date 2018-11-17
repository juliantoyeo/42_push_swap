/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 20:05:07 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/21 20:05:08 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_init(t_rank *rank, t_num **list)
{
	t_num	*lst;

	lst = *list;
	(*rank).rank = 0;
	(*rank).max = 0;
	(*rank).size = ft_list_len(*list);
	while (lst)
	{
		if (lst->num > (*rank).max)
			(*rank).max = lst->num;
		lst = lst->next;
	}
	(*rank).lowest = (*rank).max;
	while (lst)
	{
		lst->sub_zone = 0;
		lst = lst->next;
	}
	return (0);
}

int			ft_rank(t_num **list)
{
	t_rank	rank;
	t_num	*begin;

	ft_init(&rank, list);
	begin = *list;
	while (rank.rank < rank.size)
	{
		while (*list)
		{
			if ((rank.lowest > (*list)->num) && ((*list)->set != 's'))
				rank.lowest = (*list)->num;
			else if (rank.lowest == (*list)->num && ((*list)->set != 's'))
			{
				if ((*list)->num == rank.max)
					(*list)->rank = --rank.size;
				else
					(*list)->rank = rank.rank++;
				rank.lowest = rank.max;
				(*list)->set = 's';
			}
			*list = (*list)->next;
		}
		*list = begin;
	}
	return (0);
}
