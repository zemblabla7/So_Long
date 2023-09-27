/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:13:43 by casomarr          #+#    #+#             */
/*   Updated: 2023/02/08 15:57:09 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*str_in_memory(char *big)
{
	size_t	i;
	size_t	j;
	char	*in_memory;

	i = 0;
	while (big[i] != '\n' && big[i] != '\0')
		i++;
	if (big[i] != '\0')
	{
		in_memory = malloc((ft_strlen1(big) - (i + 1) + 1) * sizeof(char));
		if (in_memory == NULL)
			return (NULL);
	}
	else
	{
		free(big);
		return (NULL);
	}
	i += 1;
	j = 0;
	while (big[i])
		in_memory[j++] = big[i++];
	in_memory[j] = '\0';
	free(big);
	return (in_memory);
}

static char	*str_to_print(char *big)
{
	size_t	i;
	char	*to_print;

	i = 0;
	while (big[i] != '\n' && big[i] != '\0')
		i++;
	to_print = malloc(sizeof(char) * (i + 2));
	if (to_print == NULL)
		return (NULL);
	i = 0;
	while (big[i] != '\n' && big[i] != '\0')
	{
		to_print[i] = big[i];
		i++;
	}
	if (big[i] == '\n')
	{
		to_print[i] = big[i];
		i++;
	}
	to_print[i] = '\0';
	return (to_print);
}

static char	*until_newline(int fd, char *big)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr1(big, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		big = ft_joinstr(big, buffer);
	}
	free(buffer);
	return (big);
}

char	*get_next_line(int fd)
{
	char		*to_print;
	static char	*big;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	big = until_newline(fd, big);
	if (big == NULL)
		return (NULL);
	to_print = str_to_print(big);
	big = str_in_memory(big);
	if (big)
	{
		if (big[0] == '\0')
		{
			free(big);
			big = NULL;
		}
	}
	return (to_print);
}
