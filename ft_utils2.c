/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgardine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:32:18 by fgardine          #+#    #+#             */
/*   Updated: 2023/07/01 19:57:41 by fgardine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	recursivehex(unsigned int hexnum, int caseadd, int len)
{
	if (hexnum > 15)
	{
		len = recursivehex(hexnum / 16, caseadd, len);
		len = recursivehex(hexnum % 16, caseadd, len);
	}
	else if (hexnum > 9)
	{
		ft_putchar(hexnum + caseadd);
		len++;
	}
	else
	{
		ft_putchar(hexnum + 48);
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int hex, char casetype)
{
	int	caseadd;

	caseadd = 87;
	if (casetype == 'X')
		caseadd = 55;
	return (recursivehex(hex, caseadd, 0));
}

int	ft_recursivevoid(size_t voidnum, int len)
{
	if (voidnum > 15)
	{
		len = ft_recursivevoid(voidnum / 16, len);
		len = ft_recursivevoid(voidnum % 16, len);
	}
	else if (voidnum > 9)
	{
		ft_putchar(voidnum + 87);
		len++;
	}
	else
	{
		ft_putchar(voidnum + 48);
		len++;
	}
	return (len);
}

int	ft_putvoid(size_t voidnum)
{
	int	len;

	ft_putchar('0');
	ft_putchar('x');
	len = 2;
	return (ft_recursivevoid(voidnum, len));
}
