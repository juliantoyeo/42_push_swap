/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 05:34:56 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/20 05:34:58 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	ft_get_move(t_num **alist, t_num **blist, char option)
{
	char	*line;

	if (option == 'v')
		ft_display_stack(*alist, *blist, option, 0);
	while ((get_next_line(0, &line)))
	{
		if ((ft_move(alist, blist, line, 0)) == -1)
		{
			write(2, "Error\n", 6);
			FREE(line);
			ft_free_list(alist);
			return (0);
		}
		FREE(line);
		if (option == 'v')
			ft_display_stack(*alist, *blist, option, 0);
	}
	ft_check_result(*alist, *blist, option);
	return (0);
}

static	int	ft_process(t_lst lst, int ac, char **av, char option)
{
	char	*line;
	t_num	*alist;
	t_num	*blist;

	alist = lst.a;
	blist = lst.b;
	line = NULL;
	if ((ft_parse(&alist, ac, av)) == -1)
		write(2, "Error\n", 6);
	else
	{
		if (option == 'g')
			ft_game_mode(&alist, &blist, option);
		else
			ft_get_move(&alist, &blist, option);
	}
	ft_free_list(&alist);
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
	if (av[0] && ((ft_strcmp(av[0], "-v") == 0) || (ft_strcmp(av[0], "-g") == 0)
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
