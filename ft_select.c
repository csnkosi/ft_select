/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 12:10:28 by cnkosi            #+#    #+#             */
/*   Updated: 2017/08/19 14:21:43 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_putc(int c)
{
	return (write(2, &c, 1));
}

void	term_clr()
{
	tputs(tgetstr("cl", NULL), 1, ft_putc);
}

char	*read_line(void)
{
	char	*line;

	line = ft_strnew(4);
	while (1)
	{
		read(0, line, 4);

		if (line[0] == 27 && line[1] == 91 && line[2] == 65)
			return ("Up");
		else if (line[0] == 27 && line[1] == 91 && line[2] == 66)
			return ("Down");
		else if (line[0] == 27 && line[1] == 91 && line[2] == 67)
			return ("Right");
		else if (line[0] == 27 && line[1] == 91 && line[2] == 68)
			return ("Left");
		else if (line[0] == 27 || line[0] == '\n')
			return ("Esc");
		else if (line[0] == 32)
			return ("Space");
		else
			return ("Error");
		break;
	}
	return (NULL);
}

void	ft_underline(char *s)
{
	tputs(tgetstr("us", NULL), 1, ft_putc);
	ft_putendl(s);
	tputs(tgetstr("ue", NULL), 1, ft_putc);
}

void	ft_highlight(char *s)
{
	tputs(tgetstr("so", NULL), 1, ft_putc);
	ft_putendl(s);
	tputs(tgetstr("se", NULL), 1, ft_putc);
}

void	ft_current_arg(char *s)
{
	tputs(tgetstr("us", NULL), 1, ft_putc);
	tputs(tgetstr("so", NULL), 1, ft_putc);
	ft_putendl(s);
	tputs(tgetstr("se", NULL), 1, ft_putc);
	tputs(tgetstr("ue", NULL), 1, ft_putc);
}

void	ft_print_args(char **args, int undrln, int hlt, int ac, int *t)
{
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	term_clr();
	while (args[i])
	{
		if (t[i - 1] == 1 && undrln == i)
			ft_current_arg(args[i++]);
		else if (undrln == i)
			ft_underline(args[i++]);
		else if (t[i - 1] == 1)
			ft_highlight(args[i++]);
		else
			ft_putendl(args[i++]);
	}
}























