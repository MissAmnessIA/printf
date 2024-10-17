/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:42:56 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/17 09:13:02 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>

int putstr(char *str);
int putchar(int c);
int put_ptr_hex(unsigned long long ptr);

int	type(char c, va_list args, int bytes)
{
	if (c == 'c')
		bytes += putchar(va_arg(args, int));
	else if (c == 's')
		bytes += putstr(va_arg(args, char *));
	else if (c == 'p')
		bytes += put_ptr_hex(va_arg(args, unsigned long long));
	/*else if (c == 'd')
		bytes += putdec(va_arg(args, double));
	else if (c == 'i')
		bytes += putnbr(va_args(args, int));
	else if (c == 'u')
		bytes += putunsignedint(va_arg(args, unsigned int));
	else if (c == 'x')
		bytes += puthexmin(va_arg(args, int));
	else if (c == 'X')
		bytes += puthexmay(va_arg(args, int));
	else if (c == '%')
	{
		write (1, "%", 1);
		return (bytes + 1);
	}
	*/
	return (bytes);
}

int	putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr(char *str)
{
	int	bytes;
	
	bytes = 0;
	while (str[bytes])
	{
		write (1, &str[bytes], 1);
		bytes++;
	}
	return (bytes);
}

int put_ptr_hex(unsigned long long ptr)
{
	int	bytes;

	bytes = write (1, "0x", 2);
	if (ptr == 0)
		bytes += write (1, "0", 1);
	else if ()
}

int	ft_printf(char const *str, ...)
{
	va_list args;
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
			bytes += putchar(*str);
		str++;
	}
	va_end(args);
	return (bytes);
}

int main(void)
{
	char ch1 = 'c';
	char ch2 = 'a';
	char str[] = "Paquito el chocos";
	int size = 0;
	void *hex;
	size = ft_printf("Esto: %c es una: %c prueba: %s \n", ch1, ch2, str);
	printf("Bytes escritos: %d \n", size);
	printf("Esto es un hexadecimal: %p \n", &hex);
	return(0);
}
