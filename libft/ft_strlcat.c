/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:47:57 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/25 17:52:06 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l_src;

	if (dst == NULL)
	{
		i = 0;
	}
	else
	{
		i = ft_strlen(dst);
	}
	j = ft_strlen(src);
	l_src = j;
	if (size == 0 || i > size)
		return (size + j);
	j = 0;
	while (src[j] && ((i + j) < size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + l_src);
}

/*
int main ()
{
	char src[] = "lalalala";
	char dest[] = "hola";
	int n = 50; // qd overflow la vraie fonction fait n'imp et la mienne pas.

	printf("Ma fonction : %lu\n", ft_strlcat(dest, src, n));
	printf("Ma fonction : %s\n", dest);
	// printf("Vraie fonction : %lu\n", strlcat(dest, src, n));
	// printf("Vraie fonction : %s\n", dest);

	return (0);
}
*/
