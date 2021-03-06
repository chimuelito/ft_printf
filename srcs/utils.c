/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncatrien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:19:46 by ncatrien          #+#    #+#             */
/*   Updated: 2021/01/20 14:41:06 by ncatrien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	format_init(t_format *f, const char *fmt)
{
	f->format = fmt;
	f->pos = 0;
	f->nprinted = 0;
}

void	format_zero(t_format *f)
{
	f->minus = 0;
	f->zero = 0;
	f->point = 0;
	f->width = 0;
	f->hashtag = 0;
	f->space = 0;
	f->plus = 0;
	f->precision = 0;
	f->neg_precision = 0;
	f->sign = 0;
	f->sign_symb = 0;
}

int		padding(char c, int n)
{
	int i;
	int ret;

	i = -1;
	ret = 0;
	while (++i < n)
	{
		ft_putchar_fd(c, 1);
		ret++;
	}
	return (ret);
}

int		number_len(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

int		putstr_n(char *str, int n)
{
	int ret;

	ret = 0;
	while (*str && n--)
	{
		ft_putchar_fd(*str, 1);
		str++;
		ret++;
	}
	return (ret);
}
