/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:42:56 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/25 17:15:38 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include <stdio.h>

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

int main()
{
	char *c = NULL;
	int bytes = 0;
	bytes = ft_printf("%s \n",c);
	printf("Bytes: %d \n", bytes);
	bytes = printf("%s \n", c);
	printf("Bytes: %d \n", bytes);
	return 0;
}
