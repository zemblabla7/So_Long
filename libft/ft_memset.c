/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:31:43 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:47 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, char c, size_t n)
{
	long unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*
int main ()
{
    char str[] = "mandarine pomme banane prune";

    memset(str, '.', 10);
    printf("%s\n", str);

    ft_memset(str, '.', 10);
    printf("%s\n", str);

    return (0);
}
*/
