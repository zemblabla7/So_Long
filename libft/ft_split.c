/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:18:56 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/27 12:06:28 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_length(char *str, char c)
{
	size_t	len;

	len = 0;
	while (*str == c)
			++str;
	while (str[len] != c && str[len] != '\0')
		++len;
	return (len);
}

size_t	count_words(char *str, char c)
{
	size_t	nb_of_words;
	size_t	i;

	nb_of_words = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i] != '\0')
			&& (str[i + 1] == c || str[i + 1] == '\0'))
		{
			nb_of_words++;
		}
		i++;
	}
	return (nb_of_words);
}

void	write_words(char *dest, char *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
}

int	write_split(char **string, char *str, char c)
{
	size_t	word;
	size_t	total_nb_of_words;
	size_t	i;

	word = 0;
	total_nb_of_words = count_words(str, c);
	while (word < total_nb_of_words)
	{
		string[word] = malloc(sizeof(char) * (word_length(str, c) + 1));
		if (string[word] == NULL)
			return (EXIT_FAILURE);
		i = 0;
		while (str[i] == c && str[i] != '\0')
			++i;
		str += i;
		write_words(string[word], str, c);
		str = str + word_length(str, c);
		word++;
	}
	string[total_nb_of_words] = NULL;
	return (EXIT_SUCCESS);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = count_words((char *)s, c);
	string = malloc(sizeof(char *) * (words + 1));
	if (string == NULL)
		return (NULL);
	if (write_split(string, (char *)s, c) == EXIT_FAILURE)
	{
		while (words > 0)
			free(string[--words]);
		free(string);
	}
	return (string);
}

/*
int main()
{
	char s[] = "ca ro";
	char c = ' ';

	int i = 0;
	char **split;
	split = ft_split(s, c);
	while(split[i])
    {
        printf("%s\n", split[i]);
        i++;
    }
    return 0;
}
*/
