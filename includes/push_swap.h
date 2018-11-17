/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 22:38:41 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/28 18:54:31 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <limits.h>

typedef	struct		s_num
{
	int				num;
	int				rank;
	int				zone;
	int				sub_zone;
	char			set;
	struct s_num	*next;
}					t_num;

typedef	struct		s_rank
{
	int				lowest;
	int				max;
	int				rank;
	int				size;
}					t_rank;

typedef	struct		s_sum
{
	int				sum1;
	int				sum2;
	int				sum3;
}					t_sum;

typedef	struct		s_lst
{
	t_num			*a;
	t_num			*b;
	int				current;
}					t_lst;

typedef	struct		s_zone
{
	int				zone;
	int				sub_zone;
}					t_zone;

typedef	struct		s_nb
{
	int				count;
	int				size;
	int				mid;
}					t_nb;

typedef	struct		s_count
{
	int				count;
	int				count_1;
	int				count_2;
	int				count_3;
}					t_count;

int					ft_parse(t_num **list, int ac, char **av);
int					ft_rank(t_num **list);
int					ft_swap(t_num **list);
int					ft_rotate(t_num **list);
int					ft_rrotate(t_num **list);
int					ft_push(t_num **dest, t_num **src);
int					ft_push_swap(t_num **a, t_num **b);
int					ft_display_stack(t_num *a, t_num *b, char opt, int count);
int					ft_get_zone(t_num **list);
int					ft_get_low_max(t_num *list, int zone, t_rank *rank);
int					ft_check_zone_left(t_num *list, int zone);
int					ft_check_current(t_num *list, int cur, int zone, char *c);
int					ft_get_sub_max(t_num *list, int sub, t_rank *rank);
int					ft_get_sub_mid(t_num *list, int sub);
int					ft_get_sub_zone(t_num *list, int zone);
int					ft_list_len(t_num *list);
int					ft_copy_list(t_num *src, t_num **dst);
int					ft_free_list(t_num **list);
int					ft_move(t_num **a, t_num **b, char *str, int vers);
int					ft_check_sequence(t_num **list);
int					ft_push_swap_sort(t_num **a, t_num **b);
int					ft_choose_push_swap(t_num **a, t_num **b, int vers);
int					ft_check_result(t_num *alist, t_num *blist, char option);
int					ft_get_mid(t_num *list);
int					ft_simple_1(t_num **a, t_num **b, int vers);
int					ft_simple_2(t_num **a, t_num **b, int vers);
int					ft_simple_3(t_num **a, t_num **b, int vers);
int					ft_sort1(t_lst *lst, int zone, int sub_zone);
int					ft_sort2(t_lst *lst, int zone, int sub_zone);
int					ft_sort3(t_lst *lst, int zone, int sub_zone);
int					ft_sort4(t_lst *lst, int zone, int sub_zone);
int					ft_game_mode(t_num **alist, t_num **blist, char option);
t_num				*ft_get_last(t_num *list);

#endif
