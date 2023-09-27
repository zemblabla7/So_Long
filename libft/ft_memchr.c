/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:32:15 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/25 17:50:53 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
int main ()
{
    char str[] = "carolina";
    //unsigned char c = 'a';
	int c = 2 + 256;
    size_t n = 3;

    printf("ma fonction : %s\n", (char *)ft_memchr(str, c, n));
    printf("vraie fonction : %s\n", (char *)memchr(str, c, n));

    return (0);
}
*/
