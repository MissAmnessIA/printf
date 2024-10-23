/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:26:18 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/23 19:26:20 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

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

int	putchr(int c, int bytes)
{
	write(1, &c, 1);
	bytes++;
	return (bytes);
}
