/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 04:55:04 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/20 04:55:05 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_sort3_part1(t_lst *lst, int zone, int sub_zone, char *location)
{
	if (lst->a->rank == lst->current && lst->a->sub_zone == sub_zone)
	{
		if (lst->b && lst->b->zone == zone && lst->b->sub_zone != sub_zone)
			ft_move(&lst->a, &lst->b, "rr", 1);
		else
			ft_move(&lst->a, &lst->b, "ra", 1);
		lst->current++;
		ft_check_current(lst->a, lst->current, zone, location);
	}
	else
		ft_move(&lst->a, &lst->b, "pb", 1);
	return (0);
}

static int	ft_sort3_part2(t_lst *lst, int zone, int sub_zone, char *location)
{
	if (lst->b->rank == lst->current && lst->b->sub_zone == sub_zone)
	{
		ft_move(&lst->a, &lst->b, "pa", 1);
		if (lst->b && lst->b->zone == zone && lst->b->sub_zone != sub_zone)
			ft_move(&lst->a, &lst->b, "rr", 1);
		else
			ft_move(&lst->a, &lst->b, "ra", 1);
		lst->current++;
		ft_check_current(lst->a, lst->current, zone, location);
	}
	else if (lst->b->sub_zone == sub_zone)
		ft_move(&lst->a, &lst->b, "pa", 1);
	else
		ft_move(&lst->a, &lst->b, "rb", 1);
	return (0);
}

int			ft_sort3(t_lst *lst, int zone, int sub_zone)
{
	int		round;
	char	location;
	t_rank	rank;

	round = 0;
	ft_get_sub_max(lst->b, sub_zone, &rank);
	while (round == 0)
	{
		ft_check_current(lst->a, lst->current, zone, &location);
		if (lst->current == (rank.max + 1))
			round = 1;
		else
		{
			if (lst->a && location == 'a')
				ft_sort3_part1(lst, zone, sub_zone, &location);
			else if (lst->b && location == 'b')
				ft_sort3_part2(lst, zone, sub_zone, &location);
		}
	}
	return (0);
}
