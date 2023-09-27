/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:32:27 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/21 16:43:49 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return (((char *)big));
	if (len == 0)
		return (NULL);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (NULL);
}

/*
int    main(void)
{
    char    *s1 = "karl et caro galerent";
    char    *s2 = "hhh";
    size_t    n = 50;

	//printf("%s\n", (char *)ft_strnstr(((void*)0), "fake", 0));

    //printf("\nRegular Function:::%d:::\n", strnstr(s1, s2, n));
   	printf("Amazing Function:::%s:::\n\n", ft_strnstr(s1, s2, n));
    return (0);
}
*/
