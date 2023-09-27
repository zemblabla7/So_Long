/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:41:45 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/04 14:30:06 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long long ptr, int base_len)
{
	int					i;
	unsigned long long	n;

	i = 0;
	if (ptr == 0)
		return (1);
	if (ptr < 0)
	{
		n = ptr * -1;
		i++;
	}
	else
		n = ptr;
	while (n > 0)
	{
		n = n / base_len;
		i++;
	}
	return (i);
}

int	ft_nbrlen_unsigned(unsigned long long ptr, int base_len)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		ptr = ptr / base_len;
		i++;
	}
	return (i);
}

int	ft_is_pointer(unsigned long long ptr, int trigger)
{
	char	*base;

	if ((void *)ptr == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	base = "0123456789abcdef";
	if (trigger == 1)
		ft_putstr("0x");
	if (ptr > 15)
		ft_is_pointer((ptr / 16), 0);
	ft_putchar(base[ptr % 16]);
	return (ft_nbrlen_unsigned(ptr, 16) + 2);
}
