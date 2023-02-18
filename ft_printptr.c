/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 15:19:34 by psadeghi      #+#    #+#                 */
/*   Updated: 2022/11/01 17:17:25 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkzeroptr(unsigned long int n)
{
	if (n == 0)
		ft_putchar(48);
	return (1);
}

int	ft_printptr(unsigned long int n)
{
	unsigned long int	quotient;
	int					i;
	unsigned long int	temp;
	char				hexnumber[100];
	unsigned long int	size;

	i = 0;
	quotient = n;
	size = 0;
	if (n == 0)
		size += ft_checkzeroptr(n);
	while (quotient != 0)
	{
		temp = quotient % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hexnumber[i++] = temp;
		quotient = quotient / 16;
	}
	i = i - 1;
	while (i >= 0)
		size += ft_putchar(hexnumber[i--]);
	return (size);
}
