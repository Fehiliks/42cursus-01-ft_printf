/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgardine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:22:09 by fgardine          #+#    #+#             */
/*   Updated: 2023/07/01 20:48:59 by fgardine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	typecheck(va_list args, char ichar, int outputlen)
{
	if (ichar == 'c')
	{
		ft_putchar(va_arg(args, int));
		outputlen++;
	}
	else if (ichar == 's')
		outputlen = ft_putstr(va_arg(args, char *), outputlen);
	else if (ichar == 'p')
		outputlen += ft_putvoid(va_arg(args, size_t));
	else if (ichar == 'd' || ichar == 'i')
		outputlen = ft_putint(va_arg(args, int), outputlen);
	else if (ichar == 'u')
		outputlen += ft_putunsigned(va_arg(args, unsigned int), 0);
	else if (ichar == 'x' || ichar == 'X')
		outputlen += ft_puthex(va_arg(args, unsigned int), ichar);
	else if (ichar == '%')
	{
		ft_putchar('%');
		outputlen++;
	}
	return (outputlen);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		outputlen;
	va_list	args;

	i = 0;
	outputlen = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[++i])
		{
			outputlen = typecheck(args, str[i], outputlen);
			i++;
			continue ;
		}
		ft_putchar(str[i++]);
		outputlen++;
	}
	va_end(args);
	return (outputlen);
}
/*
#include "stdio.h"
int	main(void)
{
	char	*str = "CRANKY";
	char	c = 'c';
//	int		x = 4294967296;
	int		outp;
	void *z = "adsf1234";

//	outp = printf(" %s \n", NULL);
	outp = ft_printf(" %s \n", NULL);

	printf("cool %p test %s rock %c\n", z, str, c);
//	outp = ft_printf("cool %p test %s rock %c\n", z, str, c);
	printf("%i", outp);
}
*/
