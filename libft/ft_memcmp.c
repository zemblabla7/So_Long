/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:47:37 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/25 17:51:20 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*
int main ()
{
    char str1[] = "menjar";
    char str2[] = "menhir";
    size_t n = 5;

    ft_memcmp(str1, str2, n);
    printf("Ma fonction : %d\n", ft_memcmp(str1, str2, n));

    memcmp(str1, str2, n);
    printf("Vraie fonction : %d\n", memcmp(str1, str2, n));

    return(0);
}
*/
