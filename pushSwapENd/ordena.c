/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordena.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:56:20 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/11 17:28:26 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ordena_a(t_stack **a)
{
	if (((*a)->num < (*a)->next->num)
		&& ((*a)->next->num < (*a)->next->next->num))
		return (1);
	else
	{
		if ((*a)->num < (*a)->next->num)
			ra(a);
		else if ((*a)->num < (*a)->next->num)
			rra(a);
		if ((*a)->num > (*a)->next->num)
			sa(*a);
		return (1);
	}
}
int	ordena_b(t_stack **a)
{
	if (((*a)->num > (*a)->next->num)
		&& ((*a)->next->num > (*a)->next->next->num))
		return (1);
	else
	{
		if ((*a)->num < (*a)->next->num)
			rb(a);
		else if ((*a)->num > (*a)->next->num)
			rrb(a);
		if ((*a)->num < (*a)->next->num)
			sb(*a);
		return (1);
	}
}

int	ordenado(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (1);
	tmp = a;
	while (tmp->next)
	{
		//printf("Comparando: %d con %d\n", tmp->num, tmp->next->num);
		if (tmp->next->num < tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
