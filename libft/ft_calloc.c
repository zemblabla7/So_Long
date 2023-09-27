/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casomarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:12:58 by casomarr          #+#    #+#             */
/*   Updated: 2022/11/21 18:01:38 by casomarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 && size == 0)
		return (malloc(0));
	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
int main ()
{
    int nb_of_elements = 5;
    int size_of_bytes = sizeof(int);

    printf("Ma fonction = %p\n", ft_calloc(nb_of_elements, size_of_bytes));
    printf("Vraie fonction = %p\n", calloc(nb_of_elements, size_of_bytes));

    return(0);
}
*/
