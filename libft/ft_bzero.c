/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:09:40 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/21 16:21:06 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/*
int main ()
{
    int i;
    i = 0;
    char str[] = "pomme";

    //bzero(str, 2);
    ft_bzero(str, 2);

    while (i < ft_strlen(str))
    {
        printf("%c\n", str[i]);
        i++;
    }

    return (0);
}
*/
