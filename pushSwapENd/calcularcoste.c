/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcularcoste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:55:23 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/11 16:51:06 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost_a(t_stack *a)
{
	int		size;
	int		cost;
	t_stack	*tmp;

	size = ft_lstsize(&a);
	cost = 1;
	tmp = a;
	while (tmp)
	{
		if (tmp->pos == 1)
			break ;
		cost++;
		tmp = tmp->next;
	}
	if (cost > size / 2)
		cost = size - cost;
	return (cost);
}

int	calculate_cost_b(t_stack *b, t_stack *num)
{
	int		size;
	int		cost;
	t_stack	*tmp;

	size = ft_lstsize(&b);
	cost = 1;
	tmp = b;
	while (tmp)
	{
		if (tmp->num == num->num)
			break ;
		cost++;
		tmp = tmp->next;
	}
	if (cost > size / 2)
	{
		cost = size - cost;
	}
	return (cost);
}

void	calculacoste(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	int		cost_a;
	int		cost_b;

	tmp_a = *a;
	while (tmp_a)
	{
		cost_a = calculate_cost_a(tmp_a);
		cost_b = calculate_cost_b(*b, tmp_a->target);
		tmp_a->cost = cost_a + cost_b;
		tmp_a = tmp_a->next;
	}
}
