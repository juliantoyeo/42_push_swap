/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:54:45 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/19 16:54:47 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		ft_move_p(t_num **a, t_num **b, char *str, int vers)
{
	if (str[1] == 'a')
		ft_push(a, b);
	else if (str[1] == 'b')
		ft_push(b, a);
	else
		return (-1);
	if (vers == 1)
		ft_putendl(str);
	else if (vers == 2)
		ft_printf("\033[92;m%s\n\033[0m", str);
	return (0);
}

static int		ft_move_s(t_num **a, t_num **b, char *str, int vers)
{
	if (str[1] == 'a')
		ft_swap(a);
	else if (str[1] == 'b')
		ft_swap(b);
	else if (str[1] == 's')
	{
		ft_swap(a);
		ft_swap(b);
	}
	else
		return (-1);
	if (vers == 1)
		ft_putendl(str);
	else if (vers == 2)
		ft_printf("\033[92;m%s\n\033[0m", str);
	return (0);
}

static int		ft_move_r(t_num **a, t_num **b, char *str, int vers)
{
	if (str[1] == 'a')
		ft_rotate(a);
	else if (str[1] == 'b')
		ft_rotate(b);
	else if (str[1] == 'r')
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else
		return (-1);
	if (vers == 1)
		ft_putendl(str);
	else if (vers == 2)
		ft_printf("\033[92;m%s\n\033[0m", str);
	return (0);
}

static int		ft_move_rr(t_num **a, t_num **b, char *str, int vers)
{
	if (str[2] == 'a')
		ft_rrotate(a);
	else if (str[2] == 'b')
		ft_rrotate(b);
	else if (str[2] == 'r')
	{
		ft_rrotate(a);
		ft_rrotate(b);
	}
	else
		return (-1);
	if (vers == 1)
		ft_putendl(str);
	else if (vers == 2)
		ft_printf("\033[92;m%s\n\033[0m", str);
	return (0);
}

int				ft_move(t_num **a, t_num **b, char *str, int vers)
{
	if ((ft_strcmp(str, "pa")) != 0 && (ft_strcmp(str, "pb")) != 0 &&
		(ft_strcmp(str, "sa")) != 0 && (ft_strcmp(str, "sb")) != 0 &&
		(ft_strcmp(str, "ra")) != 0 && (ft_strcmp(str, "rb")) != 0 &&
		(ft_strcmp(str, "rra")) != 0 && (ft_strcmp(str, "rrb")) != 0 &&
		(ft_strcmp(str, "ss")) != 0 && (ft_strcmp(str, "rr")) != 0 &&
		(ft_strcmp(str, "rrr")) != 0)
		return (-1);
	else if (str[0] == 'p')
		ERROR((ft_move_p(a, b, str, vers)) == -1, -1);
	else if (str[0] == 's')
		ERROR((ft_move_s(a, b, str, vers)) == -1, -1);
	else if (str[0] == 'r')
	{
		if (str[1] == 'r' && (str[2] == 'a' || str[2] == 'b'))
			ERROR((ft_move_rr(a, b, str, vers)) == -1, -1);
		else
			ERROR((ft_move_r(a, b, str, vers)) == -1, -1);
	}
	return (0);
}
