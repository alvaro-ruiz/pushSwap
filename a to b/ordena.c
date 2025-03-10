/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordena.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:56:20 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/01 12:16:39 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ordena_a(t_stack **a, int *movement)
{
	if (((*a)->num < (*a)->next->num)
		&& ((*a)->next->num < (*a)->next->next->num))
		return (1);
	else
	{
		if ((*a)->num < (*a)->next->num)
			rra(a, movement);
		else if ((*a)->num > (*a)->next->num)
			ra(a, movement);
		if ((*a)->num > (*a)->next->num)
			sa(*a, movement);
		return (1);
	}
}
int	ordena_b(t_stack **a, int *movement)
{
	if (((*a)->num > (*a)->next->num)
		&& ((*a)->next->num > (*a)->next->next->num))
		return (1);
	else
	{
		if ((*a)->num < (*a)->next->num)
			rb(a, movement);
		else if ((*a)->num > (*a)->next->num)
			rrb(a, movement);
		if ((*a)->num < (*a)->next->num)
			sb(*a, movement);
		return (1);
	}
}
