/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:21:25 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/21 17:58:53 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length(int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	if (n < 0)
	{
		nb = n * (-1);
		len++;
	}
	else
		nb = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*string;
	int				len;
	unsigned int	nb;

	len = length(n);
	string = malloc(sizeof(char) * (len + 2));
	if (string == NULL)
		return (NULL);
	if (n < 0)
	{
		string[0] = '-';
		nb = n * (-1);
	}
	else
		nb = n;
	while (nb >= 10)
	{
		string[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	if (nb < 10)
		string[len] = nb + '0';
	string[length(n) + 1] = '\0';
	return (string);
}

/*
int	main()
{
	int n = 45;

	printf("%s\n", ft_itoa(n));

	return(0);
}
*/
