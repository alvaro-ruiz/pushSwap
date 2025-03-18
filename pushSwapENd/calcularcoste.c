/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcularcoste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:55:23 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/18 16:38:56 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculacoste(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		len_a;
	int		len_b;

	tmp_b = *b;
	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (*b)
	{
		(*b)->cost = (*b)->pos;
		if ((*b)->pos > len_b / 2 + 1)
			(*b)->cost = len_b - ((*b)->pos);
		if ((*b)->target->pos > len_a / 2 + 1)
			(*b)->cost += (*b)->target->pos;
		else
			(*b)->cost += len_a - ((*b)->target->pos);
		*b = (*b)->next;
	}
	*b = tmp_b;
}
