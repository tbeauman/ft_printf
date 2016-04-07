/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_funcsh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 19:54:21 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/28 17:32:46 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_hd(va_list *ap, int *flags)
{
	short	d;
	int		ret;
	int		prec;

	prec = flags[12];
	ret = 0;
	d = va_arg(*ap, int);
	if (flags[13] && d == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_d(d, flags);
	if ((!flags[1] || flags[2] || prec) && flags[11])
		while (flags[11]-- > (flags[3] || flags[4])
				+ (d < 0 && prec > length_int(ABS(d), 10)) +
				(prec > length_int(d, 10) ? prec : length_int(d, 10))
				&& ret++ > -1)
			ft_putchar(' ');
	if (!flags[2])
		ret += print_d(d, flags);
	return (ret);
}

int		convert_ho(va_list *ap, int *flags)
{
	unsigned short	o;
	int				ret;
	int				prec;

	prec = flags[12];
	ret = 0;
	o = va_arg(*ap, int);
	if (flags[13] && o == 0 && !flags[0])
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_o(o, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > length_int(o, 8) && ret++ > -1)
			ft_putchar('0');
	while (flags[11]-- > (flags[0] && o != 0) +
			(flags[12] > length_int(o, 8) ? flags[12] : length_int(o, 8))
			&& ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_o(o, flags);
	return (ret);
}

int		convert_hu(va_list *ap, int *flags)
{
	unsigned short	u;
	int				ret;

	ret = 0;
	u = va_arg(*ap, int);
	if (flags[13] && u == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_u(u, flags);
	while (flags[11]-- > (flags[12] > length_unsint(u, 10) ?
				flags[12] : length_unsint(u, 10))
			&& ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_u(u, flags);
	return (ret);
}

int		convert_hx(va_list *ap, int *flags)
{
	unsigned short	x;
	int				ret;
	int				ln;

	ret = 0;
	x = va_arg(*ap, int);
	if (flags[13] && x == 0)
		return (just_print_spaces(flags));
	ln = (flags[12] > length_unsint(x, 16)) ? flags[12] : length_unsint(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_x(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_x(x, flags);
	return (ret);
}

int		convert_hbx(va_list *ap, int *flags)
{
	unsigned short	x;
	int				ret;
	int				ln;

	ret = 0;
	x = va_arg(*ap, int);
	if (flags[13] && x == 0)
		return (just_print_spaces(flags));
	ln = (flags[12] > length_unsint(x, 16)) ? flags[12] : length_unsint(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_bx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_bx(x, flags);
	return (ret);
}
