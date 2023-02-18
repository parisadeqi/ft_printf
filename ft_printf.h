/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: psadeghi <psadeghi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 18:42:10 by psadeghi      #+#    #+#                 */
/*   Updated: 2022/11/01 16:54:42 by psadeghi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(int c);
int		ft_printf(const char *format, ...);
int		ft_convertdectohexup(unsigned int n);
int		ft_convertdectohexlow(unsigned int n);
int		ft_printptr(unsigned long int n);

#endif