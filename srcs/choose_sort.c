/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:35:30 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/27 12:35:32 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_choose_push_swap(t_num **a, t_num **b, int vers)
{
	t_num	*alst;
	t_count	nb;

	alst = NULL;
	if (ft_list_len(*a) > 20)
		ft_push_swap_sort(a, b);
	else
	{
		ft_copy_list(*a, &alst);
		nb.count_1 = ft_simple_1(&alst, b, 0);
		ft_free_list(&alst);
		ft_copy_list(*a, &alst);
		nb.count_2 = ft_simple_2(&alst, b, 0);
		ft_free_list(&alst);
		ft_copy_list(*a, &alst);
		nb.count_3 = ft_simple_3(&alst, b, 0);
		ft_free_list(&alst);
		if (nb.count_1 <= nb.count_2 && nb.count_1 <= nb.count_3)
			nb.count = ft_simple_1(a, b, vers);
		else if (nb.count_2 < nb.count_1 && nb.count_2 <= nb.count_3)
			nb.count = ft_simple_2(a, b, vers);
		else
			nb.count = ft_simple_3(a, b, vers);
	}
	return (nb.count);
}
