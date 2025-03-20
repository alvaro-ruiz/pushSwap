/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:24:25 by aruiz-bl          #+#    #+#             */
/*   Updated: 2024/09/24 16:20:07 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*d;
	int				m;

	m = (int) n;
	d = (unsigned char *)s;
	i = 0;
	while (i < m)
	{
		d[i] = c;
		i++;
	}
	return ((void *)d);
}
