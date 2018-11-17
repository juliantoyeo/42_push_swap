/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:36:14 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/19 23:36:16 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_get_zone(t_num **list)
{
	t_num	*lst;
	t_sum	sum;
	double	size;

	lst = *list;
	size = ft_list_len(*list);
	sum.sum1 = size * (double)25 / (double)100;
	sum.sum2 = size * (double)50 / (double)100;
	sum.sum3 = size * (double)75 / (double)100;
	while (lst)
	{
		if (lst->rank <= sum.sum1)
			lst->zone = 1;
		else if (lst->rank > sum.sum1 && lst->rank <= sum.sum2)
			lst->zone = 2;
		else if (lst->rank > sum.sum2 && lst->rank <= sum.sum3)
			lst->zone = 3;
		else if (lst->rank > sum.sum3)
			lst->zone = 4;
		lst = lst->next;
	}
	return (0);
}

int			ft_get_low_max(t_num *list, int zone, t_rank *rank)
{
	t_num	*lst;

	lst = list;
	(*rank).lowest = lst->rank;
	(*rank).max = 0;
	while (lst)
	{
		if (lst->zone == zone)
		{
			if (lst->rank < (*rank).lowest)
				(*rank).lowest = lst->rank;
			else if (lst->rank > (*rank).max)
				(*rank).max = lst->rank;
		}
		lst = lst->next;
	}
	(*rank).size = (*rank).max - (*rank).lowest;
	return (0);
}

int			ft_check_zone_left(t_num *list, int zone)
{
	t_num	*lst;

	lst = list;
	while (lst)
	{
		if (lst->zone == zone)
			return (-1);
		lst = lst->next;
	}
	return (0);
}

int			ft_check_current(t_num *list, int current, int zone, char *location)
{
	t_num	*lst;

	lst = list;
	*location = 'b';
	while (lst)
	{
		if (lst->zone == zone)
		{
			if (lst->rank == current)
				*location = 'a';
		}
		lst = lst->next;
	}
	return (0);
}
