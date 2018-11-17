/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 04:58:30 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/20 04:58:31 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_sort4_part1(t_lst *lst, t_zone zone, int mid, char *location)
{
	if (lst->a->rank == lst->current && lst->a->sub_zone == zone.sub_zone)
	{
		if (lst->b && (lst->b->rank > mid))
			ft_move(&lst->a, &lst->b, "rr", 1);
		else
			ft_move(&lst->a, &lst->b, "ra", 1);
		lst->current++;
		ft_check_current(lst->a, lst->current, zone.zone, location);
	}
	else
		ft_move(&lst->a, &lst->b, "pb", 1);
	return (0);
}

static int	ft_sort4_part2(t_lst *lst, t_zone zone, int mid, char *location)
{
	if (lst->b->rank == lst->current && lst->b->sub_zone == zone.sub_zone)
	{
		ft_move(&lst->a, &lst->b, "pa", 1);
		if (lst->b && (lst->b->rank > mid))
			ft_move(&lst->a, &lst->b, "rr", 1);
		else
			ft_move(&lst->a, &lst->b, "ra", 1);
		lst->current++;
		ft_check_current(lst->a, lst->current, zone.zone, location);
	}
	else if (lst->b->rank < mid)
		ft_move(&lst->a, &lst->b, "pa", 1);
	else
		ft_move(&lst->a, &lst->b, "rb", 1);
	return (0);
}

int			ft_sort4(t_lst *lst, int zone, int sub_zone)
{
	int		round;
	int		mid;
	char	location;
	t_zone	zones;
	t_rank	rank;

	round = 0;
	mid = ft_get_sub_mid(lst->b, sub_zone);
	ft_get_sub_max(lst->b, sub_zone, &rank);
	zones.zone = zone;
	zones.sub_zone = sub_zone;
	while (round == 0)
	{
		ft_check_current(lst->a, lst->current, zone, &location);
		if (lst->current == mid)
			round = 1;
		else
		{
			if (lst->a && location == 'a')
				ft_sort4_part1(lst, zones, mid, &location);
			else if (lst->b && location == 'b')
				ft_sort4_part2(lst, zones, mid, &location);
		}
	}
	return (0);
}
