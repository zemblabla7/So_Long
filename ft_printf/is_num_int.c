/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:00:48 by casomarr          #+#    #+#             */
/*   Updated: 2023/03/02 15:38:21 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_error1_int(char *base)
{
	int	i;

	i = 0;
	if (ft_strlenprint(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	is_error2_int(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (j < ft_strlenprint(base))
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base_int(long long nbr, char *base)
{
	unsigned long long	n;

	n = 0;
	if (is_error1_int(base) == 0 || is_error2_int(base) == 0)
		return (0);
	if (nbr < 0)
	{
		n = nbr * -1;
		ft_putchar('-');
	}
	else
		n = nbr;
	if (n >= (unsigned long long)ft_strlenprint(base))
		ft_putnbr_base_int(n / ft_strlenprint(base), base);
	ft_putchar(base[n % ft_strlenprint(base)]);
	return (ft_nbrlen(nbr, ft_strlenprint(base)));
}

int	ft_is_num_int(int ptr)
{
	return (ft_putnbr_base_int(ptr, "0123456789"));
}
