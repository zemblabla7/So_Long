/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:18:59 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/21 16:45:46 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}

/*
int main ()
{
	//printf("%s\n", ft_strrchr("bonjour", 'o'));
	//printf("%s\n", ft_strrchr("bonjour", 'b' + 256));
	printf("%s\n", strrchr("bonjour", 'b' + 256));
	return 0;
}
*/
