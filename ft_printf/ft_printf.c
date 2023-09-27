/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:06:18 by casomarr          #+#    #+#             */
/*   Updated: 2023/01/04 15:04:18 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(int i, const char *arg, va_list ptr)
{
	char	type;

	type = 0;
	if (arg[i + 1] == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (arg[i + 1] == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (arg[i + 1] == 'd' || arg[i + 1] == 'i')
		return (ft_is_num_int(va_arg(ptr, int)));
	else if (arg[i + 1] == 'x' || arg[i + 1] == 'X' || arg[i + 1] == 'u')
		return (ft_is_num_u(va_arg(ptr, long long), arg[i + 1]));
	else if (arg[i + 1] == 'p')
		return (ft_is_pointer(va_arg(ptr, unsigned long long), 1));
	else if (arg[i + 1] == '%')
		return (ft_putchar('%'));
	else
	{
		ft_putchar('%');
		ft_putchar(arg[i + 1]);
		return (2);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;
	int		length;

	va_start (ptr, format);
	i = 0;
	length = 0;
	while (format[i])
	{
		if (format[i] != '%')
			length += ft_putchar(format[i++]);
		else
		{
			length += ft_format(i, format, ptr);
			i += 2;
		}
	}
	va_end(ptr);
	return (length);
}
