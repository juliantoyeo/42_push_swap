/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 04:37:01 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/20 04:37:02 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_sort2_part1(t_lst *lst, int zone, int sub_zone, char *location)
{
	if (lst->a->rank == lst->current && lst->a->sub_zone == sub_zone)
	{
		ft_move(&lst->a, &lst->b, "ra", 1);
		lst->current++;
		ft_check_current(lst->a, lst->current, zone, location);
	}
	else
		ft_move(&lst->a, &lst->b, "pb", 1);
	return (0);
}

static int	ft_sort2_part2(t_lst *lst, int zone, int sub_zone, char *location)
{
	t_num	*blast;

	blast = ft_get_last(lst->b);
	if (lst->b->rank == lst->current && lst->b->sub_zone == sub_zone)
	{
		ft_move(&lst->a, &lst->b, "pa", 1);
		ft_move(&lst->a, &lst->b, "ra", 1);
		lst->current++;
		ft_check_current(lst->a, lst->current, zone, location);
	}
	else if (lst->b->sub_zone == sub_zone)
		ft_move(&lst->a, &lst->b, "pa", 1);
	else if (blast->zone == zone)
		ft_move(&lst->a, &lst->b, "rrb", 1);
	return (0);
}

int			ft_sort2(t_lst *lst, int zone, int sub_zone)
{
	int		round;
	char	location;
	t_rank	rank;
	t_num	*blast;

	round = 0;
	ft_get_sub_max(lst->b, sub_zone, &rank);
	while (round == 0)
	{
		blast = ft_get_last(lst->b);
		ft_check_current(lst->a, lst->current, zone, &location);
		if (lst->current == (rank.max + 1) && (blast->zone == (zone + 1)))
			round = 1;
		else
		{
			if (lst->a && location == 'a')
				ft_sort2_part1(lst, zone, sub_zone, &location);
			else if (lst->b && location == 'b')
				ft_sort2_part2(lst, zone, sub_zone, &location);
		}
	}
	return (0);
}
