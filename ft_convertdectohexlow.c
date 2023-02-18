/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convertdectohexlow.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 14:35:52 by psadeghi      #+#    #+#                 */
/*   Updated: 2022/11/01 17:01:48 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkzerolow(unsigned int n)
{
	if (n == 0)
		ft_putchar(48);
	return (1);
}

int	ft_convertdectohexlow(unsigned int n)
{
	unsigned int	quotient;
	int				i;
	unsigned int	temp;
	char			hexnumber[100];
	int				size;

	i = 0;
	quotient = n;
	size = 0;
	if (n == 0)
		size += ft_checkzerolow(n);
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
