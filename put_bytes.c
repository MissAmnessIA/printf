/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:05:35 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/17 08:30:33 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	putstr(char *str)
{
	int bytes;

	bytes = 0;
	while (str[bytes])
	{
		write(1, &str[bytes], 1);
		bytes++;
	}
	return (bytes);
}


