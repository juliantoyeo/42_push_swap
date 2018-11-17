/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 03:36:42 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/05 03:36:44 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int		ft_check_int(int j, int len, int is_neg, char *av)
{
	long long	tmp;

	tmp = 0;
	while (j < len)
	{
		if (!(ft_isdigit(av[j])))
			return (-1);
		tmp = tmp * 10 + (av[j] - '0');
		if ((!is_neg && tmp > 2147483647) || (is_neg && -tmp < -2147483648))
			return (-1);
		j++;
	}
	return (0);
}

static	int		ft_valid_int(int ac, char **av)
{
	int			i;
	int			j;
	int			is_neg;

	i = 0;
	while (i < ac)
	{
		j = 0;
		is_neg = 0;
		if (av[i][j] == '-' && ft_isdigit(av[i][j + 1]))
		{
			if (is_neg == 0)
				is_neg = 1;
			else
				return (-1);
			j++;
		}
		if ((ft_check_int(j, (int)ft_strlen(av[i]), is_neg, av[i])) == -1)
			return (-1);
		i++;
	}
	return (0);
}

static	int		ft_add_num(t_num **list, int num)
{
	t_num		*new;
	t_num		*lst;

	lst = *list;
	while (lst)
	{
		if (lst->num == num)
			return (-1);
		lst = lst->next;
	}
	ERROR((new = (t_num *)malloc(sizeof(t_num))) == NULL, -1);
	new->num = num;
	new->rank = 0;
	new->zone = 0;
	new->sub_zone = 0;
	new->next = NULL;
	if (!(*list))
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
	return (0);
}

static	int		ft_process_num(t_num **list, char **av, int i, int ac)
{
	int			num;

	while (i >= 0)
	{
		num = ft_atoi(av[i]);
		if ((ft_add_num(list, num)) == -1)
		{
			if (ac == 1)
				ft_free_double(av);
			return (-1);
		}
		i--;
	}
	return (0);
}

int				ft_parse(t_num **list, int ac, char **av)
{
	int			i;

	i = ac;
	if (ac == 1)
	{
		if (!(*av)[0])
			return (-1);
		av = ft_strsplit(av[0], ' ');
		while (av[i])
			i++;
	}
	if ((ft_valid_int(i, av)) == -1)
	{
		if (ac == 1)
			ft_free_double(av);
		return (-1);
	}
	i--;
	ERROR((ft_process_num(list, av, i, ac)) == -1, -1);
	ft_rank(list);
	if (ac == 1)
		ft_free_double(av);
	return (0);
}
