/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:31:18 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/19 23:31:19 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_get_sub_low_max(t_num *list, int sub, t_rank *rank)
{
	t_num	*lst;

	lst = list;
	(*rank).lowest = lst->rank;
	(*rank).max = 0;
	while (lst)
	{
		if (lst->sub_zone == sub)
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

int			ft_get_sub_max(t_num *list, int sub, t_rank *rank)
{
	t_num	*lst;

	lst = list;
	(*rank).max = 0;
	while (lst)
	{
		if (lst->sub_zone == sub)
		{
			if (lst->rank > (*rank).max)
				(*rank).max = lst->rank;
		}
		lst = lst->next;
	}
	return (0);
}

int			ft_get_sub_mid(t_num *list, int sub)
{
	int		mid;
	t_num	*lst;
	t_rank	rank;

	lst = list;
	mid = 0;
	ft_get_sub_low_max(list, sub, &rank);
	mid = rank.lowest + (rank.size / 2);
	return (mid);
}

int			ft_get_sub_zone(t_num *list, int zone)
{
	t_num	*lst;
	t_rank	rank;
	t_sum	sum;

	lst = list;
	ft_get_low_max(list, zone, &rank);
	sum.sum1 = rank.lowest + ((double)rank.size * (double)25 / (double)100);
	sum.sum2 = rank.lowest + ((double)rank.size * (double)50 / (double)100);
	sum.sum3 = rank.lowest + ((double)rank.size * (double)75 / (double)100);
	while (lst)
	{
		if (lst->zone == zone)
		{
			if (lst->rank <= sum.sum1)
				lst->sub_zone = 1;
			else if (lst->rank > sum.sum1 && lst->rank <= sum.sum2)
				lst->sub_zone = 2;
			else if (lst->rank > sum.sum2 && lst->rank <= sum.sum3)
				lst->sub_zone = 3;
			else if (lst->rank > sum.sum3)
				lst->sub_zone = 4;
		}
		lst = lst->next;
	}
	return (0);
}
