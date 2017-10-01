/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 12:08:18 by cnkosi            #+#    #+#             */
/*   Updated: 2017/08/24 17:13:18 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exec_term(void)
{
	//char	buf[1024];
	char	buff[30];
	char	*area;
	//char	*clearscr;
	struct termios	term;

	area = buff;
	if (!canonical_on(&term))
		ft_putstr("Failed to go into canonical mode\n");
	tputs(tgetstr("cl", &area), 1, ft_putc);
	if (!canonical_off(&term))
		ft_putstr("Failure to exit canonical mode\n");

	//tgetent(buf, getenv("TERM"));
	//tputs(tgetstr("cl", &area), 1, ft_putc);
}

void	ft_select(char **args, char *line, int undrln,int hlt, int ac, int *t, int i)
{
	(i == ac - 1 && ft_strcmp(line, "Up") != 0) ? i = 0 : 0;
	(ft_strcmp(line, "Esc") == 0) ? exit(EXIT_SUCCESS) : 0;
	(ft_strcmp(line, "Error") == 0) ? ft_putstr("\n") : 0;
}

void	ft_select_loop(int ac, int *t, char **args)
{
	int		undrln;
	int		hlt = 0;
	int		i;
	char	*line;

	undrln = 1;
	i = 0;
	while (1)
	{
		ft_print_args(args, undrln, hlt, ac, t);
		line = read_line();
		ft_select(args, line, undrln, hlt, ac, t, i);
		if (ft_strcmp(line, "Down") == 0)
		{
			i++;
			(undrln + 1 < ac) ? undrln++ : (undrln = 1);
		}
		else if (ft_strcmp(line, "Up") == 0)
		{
			i--;
			(undrln == 1) ? undrln = ac - 1 : undrln--;
		}
		else if (ft_strcmp(line, "Space") == 0)
		{
			hlt = undrln;
			if (t[i] == 1)
				t[i++] = 0;
			else
				t[i++] = 1;
			(undrln + 1 < ac) ? undrln++ : (undrln = 1);
		}
	}
}

int		main(int ac, char **av)
{
	int 	*t;
	int 	i;

	i = 0;
	t = (int*)malloc(sizeof(t) * ac);
	while (i < ac)
		t[i++] = 0;
	if (ac > 1)
	{
		exec_term();
		ft_select_loop(ac, t, av);
	}
	return (0);
}