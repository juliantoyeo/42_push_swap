/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 05:47:38 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/27 05:47:39 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	ft_simple_3_part_1(t_lst *lst, char *location, t_nb *nb, int vers)
{
	if (lst->a && *location == 'a')
	{
		if (lst->a->rank == lst->current)
		{
			ft_move(&lst->a, &lst->b, "ra", vers);
			lst->current++;
			ft_check_current(lst->a, lst->current, 0, location);
		}
		else
			ft_move(&lst->a, &lst->b, "pb", vers);
		(*nb).count++;
	}
	if (lst->b && *location == 'b')
	{
		if (lst->b->rank == lst->current)
			ft_move(&lst->a, &lst->b, "pa", vers);
		else
			ft_move(&lst->a, &lst->b, "rb", vers);
		(*nb).count++;
	}
	return (0);
}

int			ft_simple_3(t_num **a, t_num **b, int vers)
{
	t_lst	lst;
	t_num	*alast;
	t_nb	nb;
	char	location;

	lst.a = *a;
	lst.b = *b;
	lst.current = 0;
	nb.count = 0;
	nb.size = ft_list_len(lst.a);
	alast = ft_get_last(lst.a);
	if (alast->rank == lst.current)
		lst.current++;
	while (lst.current < nb.size || lst.b)
	{
		ft_check_current(lst.a, lst.current, 0, &location);
		ft_simple_3_part_1(&lst, &location, &nb, vers);
	}
	*a = lst.a;
	*b = lst.b;
	return (nb.count);
}

static	int	ft_simple_2_part_1(t_lst *lst, char *location, t_nb *nb, int vers)
{
	if (lst->a->rank == lst->current)
	{
		ft_move(&lst->a, &lst->b, "ra", vers);
		lst->current++;
		ft_check_current(lst->a, lst->current, 0, location);
	}
	else if (lst->a->rank > (*nb).mid)
		ft_move(&lst->a, &lst->b, "pb", vers);
	else if (lst->a->next && lst->a->rank > lst->a->next->rank
		&& lst->a->next->rank > lst->current)
	{
		if (lst->b && lst->b->next && (lst->b->rank > lst->b->next->rank))
			ft_move(&lst->a, &lst->b, "ss", vers);
		else
			ft_move(&lst->a, &lst->b, "sa", vers);
	}
	else
		ft_move(&lst->a, &lst->b, "pb", vers);
	(*nb).count++;
	return (0);
}

static	int	ft_simple_2_part_2(t_lst *lst, t_nb *nb, int vers)
{
	if (lst->b->rank == lst->current)
		ft_move(&lst->a, &lst->b, "pa", vers);
	else if (lst->b->next && lst->b->rank > lst->b->next->rank)
	{
		if (lst->a && (lst->a->next && lst->a->rank > lst->a->next->rank)
			&& lst->a->next->rank > lst->current)
			ft_move(&lst->a, &lst->b, "ss", vers);
		else
			ft_move(&lst->a, &lst->b, "sb", vers);
	}
	else
		ft_move(&lst->a, &lst->b, "pa", vers);
	(*nb).count++;
	return (0);
}

int			ft_simple_2(t_num **a, t_num **b, int vers)
{
	t_lst	lst;
	t_num	*alast;
	t_nb	nb;
	char	location;

	lst.a = *a;
	lst.b = *b;
	lst.current = 0;
	nb.count = 0;
	nb.size = ft_list_len(lst.a);
	nb.mid = ft_get_mid(lst.a);
	alast = ft_get_last(lst.a);
	if (alast->rank == lst.current)
		lst.current++;
	while (lst.current < nb.size || lst.b)
	{
		ft_check_current(lst.a, lst.current, 0, &location);
		if (lst.a && location == 'a')
			ft_simple_2_part_1(&lst, &location, &nb, vers);
		if (lst.b && location == 'b')
			ft_simple_2_part_2(&lst, &nb, vers);
	}
	*a = lst.a;
	*b = lst.b;
	return (nb.count);
}
