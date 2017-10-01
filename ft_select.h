/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 09:59:57 by cnkosi            #+#    #+#             */
/*   Updated: 2017/08/24 16:30:44 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

//# include "termcap/include/termcap.h"
# include "libft/libft.h"
# include <termcap.h>
# include <term.h>
# include <curses.h>

char	*read_line(void);
int		ft_putc(int c);
void	ft_underline(char *s);
void	ft_highlight(char *s);
void	ft_current_arg(char *s);
void	ft_print_args(char **args, int undrln, int hlt, int ac, int *t);
int		canonical_on(struct termios *term);
int		canonical_off(struct termios *term);

#endif
