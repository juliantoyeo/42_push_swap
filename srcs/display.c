/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 08:42:02 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/27 08:42:03 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	ft_print_stack(t_num *alst, t_num *blst)
{
	ft_putchar('\n');
	while (alst || blst)
	{
		if (alst)
		{
			ft_printf("num : %i", alst->num);
			alst = alst->next;
		}
		if (!alst)
			ft_printf("\t");
		ft_printf(" \t ||  \t");
		if (blst)
		{
			ft_printf("num : %i", blst->num);
			blst = blst->next;
		}
		ft_putchar('\n');
	}
	return (0);
}

int			ft_display_stack(t_num *a, t_num *b, char option, int count)
{
	t_num	*alst;
	t_num	*blst;

	alst = a;
	blst = b;
	ft_printf("\033[92;m\na list :\t\t\033[91;mb list : \n\033[0m");
	ft_printf("\033[92;m============\t ||  \033[91;m\t============\033[0m");
	if (option == 'g')
		ft_printf("\033[38;5;99;m\t count : %d\033[0m", count);
	ft_print_stack(alst, blst);
	ft_putchar('\n');
	return (0);
}
