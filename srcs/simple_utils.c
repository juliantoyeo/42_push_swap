/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 06:27:18 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/27 06:27:19 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_get_mid(t_num *list)
{
	int		mid;
	int		size;
	t_num	*lst;

	lst = list;
	mid = 0;
	size = ft_list_len(lst);
	mid = size / 2;
	return (mid);
}

static	int	ft_add_rank(t_num **list, int rank)
{
	t_num		*new;

	ERROR((new = (t_num *)malloc(sizeof(t_num))) == NULL, -1);
	new->num = 0;
	new->rank = rank;
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

int			ft_copy_list(t_num *src, t_num **dst)
{
	t_num	*lst;
	int		*tab;
	int		size;
	int		i;

	i = ft_list_len(src);
	ERROR((tab = (int *)malloc(sizeof(int) * i)) == NULL, -1);
	size = --i;
	lst = src;
	while (lst)
	{
		tab[i] = lst->rank;
		lst = lst->next;
		i--;
	}
	i = 0;
	while (i <= size)
	{
		if ((ft_add_rank(dst, tab[i])) == -1)
			return (-1);
		i++;
	}
	FREE(tab);
	return (0);
}
