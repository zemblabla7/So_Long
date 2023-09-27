/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:00:48 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/25 17:56:15 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*newstr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && checkset(s1[start], (char *)set))
		start++;
	while (end > start && checkset(s1[end -1], (char *)set))
		end--;
	newstr = malloc(sizeof(char) * (end - start + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		newstr[i++] = s1[start++];
	newstr[i] = '\0';
	return (newstr);
}

// int main ()
// {
// 	char str[] = "lorem \n ipsum \t dolor \n sit \t amet";
// 	char set[] = " ";
// 	char *new_str = ft_strtrim("123", );
// 	printf("%s", new_str);
// 	free(new_str);
// 	return(0);
// }
