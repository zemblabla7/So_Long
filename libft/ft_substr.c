/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:14:56 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/23 15:39:42 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*new_str;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		new_str = malloc(sizeof(char) * 1);
		if (new_str == NULL)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	new_str = malloc(sizeof(char) * len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len && ((char *)s)[start] != '\0')
	{
		new_str[i++] = ((char *)s)[start++];
	}
	new_str[i] = '\0';
	return (new_str);
}

/*
int main()
{
	char *str = strdup("0123456789");
	printf("%s", ft_substr(str, 9, 10));

	char *new_str = ft_substr(str, 400, 2);
	free(new_str);

	return 0;
}
*/
