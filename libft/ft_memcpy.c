/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:38:49 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/21 16:30:04 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long unsigned int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)(src))[i];
		i++;
	}
	return ((void *)dest);
}

/*
int main ()
{
    char src[] = "ccccc";
    char dest[] = "dd";

    ft_memcpy(dest, src, 5);
    //memcpy(dest, src, 5);
    printf("%s\n", dest);

    return (0);
}
*/
