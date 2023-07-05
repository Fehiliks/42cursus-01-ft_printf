/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgardine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:48:04 by fgardine          #+#    #+#             */
/*   Updated: 2023/07/01 20:04:29 by fgardine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> //std library for malloc, free etc
# include <unistd.h> //std library for write
# include <stdarg.h> //this is the standard library for variadic functions

int		ft_printf(const char *placeholder, ...);

void	ft_putchar(char c);
int		ft_putstr(char *str, int outputlen);
int		ft_putint(int num, int len);
int		ft_putunsigned(unsigned int num, int len);
int		recursivehex(unsigned int hexnum, int caseadd, int len);
int		ft_puthex(unsigned int hex, char casetype);
int		ft_recursivevoid(size_t voidnum, int len);
int		ft_putvoid(size_t voidnum);

#endif
