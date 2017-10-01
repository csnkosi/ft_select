/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canonical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:18:04 by cnkosi            #+#    #+#             */
/*   Updated: 2017/08/24 16:48:36 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		canonical_on(struct termios *term)
{
	char	buf[1024];

	if ((tgetent(buf, getenv("TERM"))) == -1)
		return (0);
	if (tcgetattr(0, term) == -1)
		return (0);
	term->c_lflag &= ~(ECHO | ICANON);
	if ((tcsetattr(0, 0, term) == -1))
		return (0);
	return (1);
}

int		canonical_off(struct termios *term)
{
	if (tcsetattr(0, TCSANOW, term) == -1)
		return (0);
	return (1);
}
