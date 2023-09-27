/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:49:48 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/25 17:52:22 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
	{
		i = ft_strlen(src);
		return (i);
	}
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = ft_strlen(src);
	return (i);
}

/*
int main ()
{
	char dest[] = "..... hambre";
	char src[] = "Tengo";
	int size = 1;

	char dest2[] = "..... hambre";
	char src2[] = "Tengo";


	ft_strlcpy(dest, src, size);
	//printf("%s\n", dest);
	printf("moi : %s\n", src);
	printf("%li\n", ft_strlcpy(dest, src, size));


	strlcpy(dest, src, size);
	//printf("%s\n", dest);
	printf("vraie : %s\n", src);
	printf("%li\n", strlcpy(dest2, src2, size));


	return (0);
}
*/
