/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:18:58 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/25 17:50:22 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long unsigned int	i;
	char				temp;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	if ((char *)dest > (char *)src)
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			temp = ((char *)(src))[i];
			((char *)dest)[i] = temp;
			i++;
		}
	}
	return ((void *)dest);
}

/*
int main ()
{
    char src[] = "carolina";
    char dest[] = "karl_leila_raph_helia";

    ft_memmove(dest + 1, src, 4);
    printf("%s\n", dest);

    memmove(dest + 1, src, 4);
    printf("%s\n", dest);

    return (0);
}
*/
