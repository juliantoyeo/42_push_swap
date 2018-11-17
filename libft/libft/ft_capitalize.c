/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:03:24 by jyeo              #+#    #+#             */
/*   Updated: 2017/12/15 18:03:26 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_capitalize(char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		(*str)[i] = ft_toupper((*str)[i]);
		i++;
	}
	(*str)[i] = '\0';
}
