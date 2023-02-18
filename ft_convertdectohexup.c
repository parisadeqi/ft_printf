/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convertdectohexup.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 11:58:41 by psadeghi      #+#    #+#                 */
/*   Updated: 2022/11/01 17:01:29 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkzeroup(unsigned int n)
{
	if (n == 0)
		ft_putchar(48);
	return (1);
}

int	ft_convertdectohexup(unsigned int n)
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
		size += ft_checkzeroup(n);
	while (quotient != 0)
	{
		temp = quotient % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexnumber[i++] = temp;
		quotient = quotient / 16;
	}
	i = i - 1;
	while (i >= 0)
		size += ft_putchar(hexnumber[i--]);
	return (size);
}
