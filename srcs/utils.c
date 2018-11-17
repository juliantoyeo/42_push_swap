/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:14:20 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/19 23:14:22 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_list_len(t_num *list)
{
	int		size;
	t_num	*lst;

	size = 0;
	lst = list;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int			ft_check_sequence(t_num **list)
{
	t_num	*lst;

	lst = *list;
	while (lst)
	{
		if (lst->next)
		{
			if (lst->rank - lst->next->rank != -1)
				return (-1);
		}
		lst = lst->next;
	}
	return (0);
}

t_num		*ft_get_last(t_num *list)
{
	t_num	*lst;

	lst = list;
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int			ft_free_list(t_num **list)
{
	t_num	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		tmp->next = NULL;
		FREE(tmp);
	}
	*list = NULL;
	return (0);
}

int			ft_check_result(t_num *alist, t_num *blist, char option)
{
	int	res;

	res = 0;
	if (ft_check_sequence(&alist) == 0 && !blist)
	{
		if (option == 'c' || option == 'g')
			ft_printf("\033[92;mOK\n\033[0m");
		else
			ft_printf("OK\n");
		res = 1;
	}
	else
	{
		if (option == 'c' || option == 'g')
			ft_printf("\033[91;mKO\n\033[0m");
		else
			ft_printf("K0\n");
		res = -1;
	}
	return (res);
}
