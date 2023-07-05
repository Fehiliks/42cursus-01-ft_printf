/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgardine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:27:21 by fgardine          #+#    #+#             */
/*   Updated: 2023/07/05 18:17:15 by fgardine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str, int outputlen)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		outputlen += 6;
		return (outputlen);
	}
	while (str[i])
	{
		ft_putchar(str[i++]);
		outputlen++;
	}
	return (outputlen);
}

int	ft_putint(int num, int len)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		len += 11;
	}
	else if (num < 0)
	{
		ft_putchar('-');
		len++;
		num = -num;
		len = ft_putint(num, len);
	}
	else if (num > 9)
	{
		len = ft_putint(num / 10, len);
		len = ft_putint(num % 10, len);
	}
	else
	{
		ft_putchar(num + 48);
		len++;
	}
	return (len);
}

int	ft_putunsigned(unsigned int num, int len)
{
	if (num > 9)
	{
		len = ft_putunsigned(num / 10, len);
		len = ft_putunsigned(num % 10, len);
	}
	else
	{
		ft_putchar(num + 48);
		len++;
	}
	return (len);
}
