/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:42:56 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/16 11:31:13 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#inlcude <stdarg.h>

int	countarg(const char *str)
{
	int count;
	
	while (str)
	{
		if (*str == '%')
			count++;
		str++;
	}
	return (count);
}

int	ft_printf(char const *str, ...)
{
	int	numarg;
	va_list args;
	
	numarg = countarg(str);
	va_start(args, str);
	
}

