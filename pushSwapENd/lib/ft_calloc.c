/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:45:18 by aruiz-bl          #+#    #+#             */
/*   Updated: 2024/10/03 13:46:11 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		*dest;

	dest = malloc(size * nmemb);
	if (!dest)
		return (NULL);
	ft_bzero(dest, nmemb * size);
	return ((void *)dest);
}

/*int main() {
    int *arr;
    int n = 5;

    // Asigna memoria para un arreglo de 5 enteros e inicializa a 0
    arr = (int *)ft_calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Fallo en la asignación de memoria.\n");
        return 1;
    }

    // Mostrar los valores inicializados (deberían ser 0)
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Liberar la memoria asignada
    free(arr);

    return 0;
}*/