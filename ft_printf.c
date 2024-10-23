/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:42:56 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/23 09:58:53 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>

int	putstr(char *str, int bytes);
int	putchr(int c, int bytes);
int	put_ptr_hex(unsigned long long ptr, int bytes);
int	ft_putnbr(int n, int bytes);
int	unsignedint(unsigned int n, int bytes);
int	print_hex(unsigned int n, int bytes, int M);

int	type(char c, va_list args, int bytes)
{
	int					m;
	unsigned long long	dic;

	m = 0;
	if (c == 'c')
		bytes = putchr(va_arg(args, int), bytes);
	else if (c == 's')
		bytes = putstr(va_arg(args, char *), bytes);
	else if (c == 'p')
	{
		dic = va_arg(args, unsigned long long);
		if (!dic)
			bytes = putstr("(nil)", bytes);
		else
		{
			bytes = putstr("0x", bytes);
			bytes = put_ptr_hex(dic, bytes);
		}
	}
	else if (c == 'd' || c == 'i')
		bytes = ft_putnbr(va_arg(args, int), bytes);
	else if (c == 'u')
		bytes = unsignedint(va_arg(args, unsigned int), bytes);
	else if (c == 'x' || c == 'X')
	{
		if (c == 'X')
			m = 1;
		bytes = print_hex(va_arg(args, unsigned int), bytes, m);
	}
	else if (c == '%')
	{
		write (1, "%", 1);
		return (bytes + 1);
	}
	return (bytes);
}

int	putchr(int c, int bytes)
{
	write(1, &c, 1);
	bytes++;
	return (bytes);
}

int	putstr(char *str, int bytes)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	bytes += i;
	return (bytes);
}

int	put_ptr_hex(unsigned long long ptr, int bytes)
{
	if (ptr == 0)
		bytes = putchr ('0', bytes);
	if (ptr >= 16)
		bytes = put_ptr_hex(ptr / 16, bytes);
	if (ptr % 16 <= 9)
		bytes = putchr(ptr % 16 + '0', bytes);
	if (ptr % 16 > 9)
		bytes = putchr((ptr % 16) % 10 + 'a', bytes);
	return (bytes);
}

int	ft_putnbr(int n, int bytes)
{
	if (n == -2147483648)
	{
		bytes = putstr("-2147483648", bytes);
		return (bytes);
	}
	if (n < 0)
	{
		bytes = putchr ('-', bytes);
		n *= -1;
	}
	if (n >= 10)
		bytes = ft_putnbr(n / 10, bytes);
	bytes = putchr(n % 10 + '0', bytes);
	return (bytes);
}

int	unsignedint(unsigned int n, int bytes)
{
	if (n >= 10)
		bytes = unsignedint(n / 10, bytes);
	bytes = putchr(n % 10 + '0', bytes);
	return (bytes);
}

int	print_hex(unsigned int n, int bytes, int M)
{
	if (n == 0)
		bytes = putchr ('0', bytes);
	if (n >= 16)
		bytes = print_hex(n / 16, bytes, M);
	if (n % 16 <= 9)
		bytes = putchr(n % 16 + '0', bytes);
	if (n % 16 > 9)
	{
		if (M)
			bytes = putchr((n % 16) % 10 + 'A', bytes);
		else
			bytes = putchr((n % 16) % 10 + 'a', bytes);
	}
	return (bytes);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		bytes;

	bytes = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bytes = type(*str, args, bytes);
		}
		else
			bytes = putchr(*str, bytes);
		str++;
	}
	va_end(args);
	return (bytes);
}
