/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:13:03 by psadeghi      #+#    #+#                 */
/*   Updated: 2022/11/03 13:52:38 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char	*s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += write (1, "-", 1);
		n = n * -1 ;
	}
	if (n >= 0 && n <= 9)
	{
		n = n + 48;
		count += write (1, &n, 1);
	}
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	return (count);
}

int	ft_putunsignednbr(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n >= 0 && n <= 9)
	{
		n = n + 48;
		count += write (1, &n, 1);
	}
	else
	{
		count += ft_putunsignednbr(n / 10);
		count += ft_putunsignednbr(n % 10);
	}
	return (count);
}

int	ft_checkformat(const char *format, va_list ap, int i)
{
	int	answer;

	answer = 0;
	if (format[i] == 'c')
		answer += ft_putchar(va_arg(ap, int));
	if (format[i] == 'u')
		answer += ft_putunsignednbr(va_arg(ap, int));
	if (format[i] == 's')
		answer += ft_putstr(va_arg(ap, char *));
	if (format[i] == 'd')
		answer += ft_putnbr(va_arg(ap, int));
	if (format [i] == 'i')
		answer += ft_putnbr(va_arg(ap, int));
	if (format[i] == '%')
		answer += ft_putchar('%');
	if (format[i] == 'X')
		answer += ft_convertdectohexup(va_arg(ap, int));
	if (format[i] == 'x')
		answer += ft_convertdectohexlow(va_arg(ap, int));
	if (format[i] == 'p')
	{
		answer += ft_putstr("0x");
		answer += ft_printptr((unsigned long)va_arg(ap, void *));
	}
	return (answer);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		answer;

	va_start(ap, format);
	i = 0;
	answer = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			answer += ft_checkformat(format, ap, i);
		}
		else
			answer += ft_putchar(format[i]);
		if (format[i] != '\0')
			i++;
	}
	va_end(ap);
	return (answer);
}

/*
int	main()
{
	//ft_printf("%c\n", 'p');
	//ft_printf("%s\n", "Paris");
	int i = ft_printf("%p\n", "");
	ft_printf("%d\n", i);
	//int j = ft_printf ("%X\n", 0);
	//ft_printf("%d\n", j);
	int j = printf("%p\n", "");
	printf("%d\n", j);
}
*/