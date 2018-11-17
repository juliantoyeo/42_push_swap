/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 10:19:11 by jyeo              #+#    #+#             */
/*   Updated: 2018/01/27 10:19:12 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <locale.h>

static	int	ft_print_game(t_num **alist, t_num **blist)
{
	int		fd;
	char	*line;
	wchar_t	*str;

	str = L"\n======== WELCOME TO THE GAME MODE ========\n\n";
	if (ft_check_sequence(alist) == 0 && !(*blist))
	{
		ft_printf("This sequence is already sorted please retry\n");
		return (-1);
	}
	if (!(fd = open("srcs/game_text/game.txt", O_RDONLY)))
		return (0);
	ft_print_colourful(str, 126);
	while ((get_next_line(fd, &line)))
	{
		ft_printf("%s\n", line);
		FREE(line);
	}
	ft_printf("\033[30;40m\n(SECRET!!)");
	ft_printf("\n- Type “ft_cheat” to display the answer %C\n\033[0m", L'😏');
	if (close(fd) == -1)
		return (0);
	return (0);
}

static	int	ft_man(int fd, char **line)
{
	char	*text;

	text = NULL;
	FREE(*line);
	ft_printf("Choose language : 'fr' or 'en'\n");
	get_next_line(0, line);
	if (ft_strcmp(*line, "fr") == 0)
		text = "srcs/game_text/instruction_fr.txt";
	else if (ft_strcmp(*line, "en") == 0)
		text = "srcs/game_text/instruction_en.txt";
	else
		ft_printf("Incorrect input!\n");
	FREE(*line);
	if (text)
	{
		ERROR((!(fd = open(text, O_RDONLY))), -1);
		while ((get_next_line(fd, line)))
		{
			ft_printf("%s\n", *line);
			FREE(*line);
		}
		ERROR((close(fd) == -1), -1);
	}
	FREE(*line);
	return (0);
}

static	int	ft_game_process(t_num **alist, t_num **blist, char **line, int *c)
{
	t_num	*alst;

	alst = NULL;
	if ((ft_strcmp(*line, "ft_cheat") == 0))
	{
		FREE(*line);
		ft_copy_list(*alist, &alst);
		ft_choose_push_swap(&alst, blist, 1);
		ft_free_list(&alst);
		ft_print_colourful(L"YOU NOOB!!🤣\n", 126);
	}
	else
	{
		if ((ft_move(alist, blist, *line, 0)) == -1)
		{
			write(2, "Error\n", 6);
			FREE(*line);
			ft_free_list(alist);
			return (-1);
		}
		(*c)++;
	}
	return (0);
}

static	int	ft_game(t_num **alist, t_num **blist, char option, int *count_1)
{
	int		fd;
	char	*line;
	t_num	*alst;

	fd = 0;
	alst = NULL;
	ft_display_stack(*alist, *blist, option, *count_1);
	while ((get_next_line(0, &line)))
	{
		if ((ft_strcmp(line, "man") == 0))
			ft_man(fd, &line);
		else
			ERROR((ft_game_process(alist, blist, &line, count_1)) == -1, -1);
		FREE(line);
		ft_display_stack(*alist, *blist, option, *count_1);
	}
	return (0);
}

int			ft_game_mode(t_num **alist, t_num **blist, char option)
{
	int		count;
	int		count_1;
	t_num	*alst;

	count = 0;
	count_1 = 0;
	alst = NULL;
	setlocale(LC_ALL, "");
	ERROR((ft_print_game(alist, blist)) == -1, 0);
	ft_copy_list(*alist, &alst);
	count = ft_choose_push_swap(&alst, blist, 0);
	ft_free_list(&alst);
	ft_printf("\nThe AI could sort this in %d steps can you beat it?\n", count);
	ERROR((ft_game(alist, blist, option, &count_1)) == -1, 0);
	ft_check_result(*alist, *blist, option);
	if (count_1 < count && (ft_check_sequence(alist) == 0 && !(*blist)))
		ft_print_colourful(L"YOU WIN!!\n", 126);
	else if (count_1 == count && (ft_check_sequence(alist) == 0 && !(*blist)))
		ft_printf("\033[94;mIT IS A DRAW\n\033[0m");
	else
		ft_printf("\033[91;mYOU LOSE :(\n\033[0m");
	ft_printf("Score : \nPlayer : %d vs AI : %d\n", count_1, count);
	return (0);
}
