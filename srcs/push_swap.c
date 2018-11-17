/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 06:52:31 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/27 06:52:32 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	ft_process(t_lst lst, int ac, char **av, char option)
{
	int		vers;
	t_num	*alist;
	t_num	*blist;

	alist = lst.a;
	blist = lst.b;
	vers = 1;
	if (option == 'c')
		vers = 2;
	if ((ft_parse(&alist, ac, av)) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
	{
		if (ft_check_sequence(&alist) == -1 || blist)
			ft_choose_push_swap(&alist, &blist, vers);
	}
	if (option == 'v')
		ft_display_stack(alist, blist, option, 0);
	ft_free_list(&alist);
	ft_free_list(&blist);
	return (0);
}

int			main(int ac, char **av)
{
	t_lst	lst;
	char	option;

	ac--;
	av++;
	lst.a = NULL;
	lst.b = NULL;
	if (av[0] && ((ft_strcmp(av[0], "-v") == 0)
		|| (ft_strcmp(av[0], "-c") == 0)))
	{
		option = av[0][1];
		ac--;
		av++;
	}
	if (ac == 0)
		return (0);
	ft_process(lst, ac, av, option);
	return (0);
}
