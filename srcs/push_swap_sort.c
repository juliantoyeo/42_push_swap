/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 06:52:20 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/27 06:52:24 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_push_zone_down_pro(t_lst *lst, int zone1, int zone2)
{
	if (lst->a)
	{
		if ((lst->a->zone == zone1) || (lst->a->zone == zone2))
			ft_move(&lst->a, &lst->b, "pb", 1);
		else if (lst->a->zone != 1)
		{
			if (lst->b && lst->b->zone == zone2)
				ft_move(&lst->a, &lst->b, "rr", 1);
			else
				ft_move(&lst->a, &lst->b, "ra", 1);
		}
	}
	if (lst->b)
	{
		if (lst->b->zone == zone2)
		{
			if (lst->a && (lst->a->zone != zone1 &&
				lst->a->zone != zone2) && lst->a->zone != 1)
				ft_move(&lst->a, &lst->b, "rr", 1);
			else
				ft_move(&lst->a, &lst->b, "rb", 1);
		}
	}
	return (0);
}

int			ft_push_zone_down(t_lst *lst, int zone1, int zone2)
{
	int		round;

	round = 0;
	while (round == 0)
	{
		if ((ft_check_zone_left(lst->a, zone1) == 0) &&
			(ft_check_zone_left(lst->a, zone2) == 0))
			round = 1;
		else
			ft_push_zone_down_pro(lst, zone1, zone2);
	}
	return (0);
}

static	int	ft_push_swap_part_1(t_lst *lst)
{
	ft_push_zone_down(lst, 1, 2);
	ft_get_sub_zone(lst->b, 1);
	ft_sort1(lst, 1, 1);
	ft_sort2(lst, 1, 2);
	ft_sort1(lst, 1, 3);
	ft_sort2(lst, 1, 4);
	ft_get_sub_zone(lst->b, 2);
	ft_sort3(lst, 2, 1);
	ft_sort3(lst, 2, 2);
	ft_sort3(lst, 2, 3);
	ft_sort4(lst, 2, 4);
	ft_sort3(lst, 2, 4);
	return (0);
}

int			ft_push_swap_sort(t_num **a, t_num **b)
{
	t_lst	lst;

	lst.a = *a;
	lst.b = *b;
	lst.current = 0;
	ft_get_zone(&lst.a);
	ft_push_swap_part_1(&lst);
	ft_push_zone_down(&lst, 3, 4);
	ft_get_sub_zone(lst.b, 3);
	ft_sort1(&lst, 3, 1);
	ft_sort2(&lst, 3, 2);
	ft_sort1(&lst, 3, 3);
	ft_sort2(&lst, 3, 4);
	ft_get_sub_zone(lst.b, 4);
	ft_sort3(&lst, 4, 1);
	ft_sort3(&lst, 4, 2);
	ft_sort3(&lst, 4, 3);
	ft_sort4(&lst, 4, 4);
	ft_sort3(&lst, 4, 4);
	*a = lst.a;
	*b = lst.b;
	return (0);
}
