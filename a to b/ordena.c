/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordena.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:56:20 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/10 13:20:00 by aruiz-bl         ###   ########.fr       */
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

int	ordenado(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (1);
	tmp = a;
	while (tmp->next)
	{
		//printf("Comparando: %d con %d\n", tmp->num, tmp->next->num); 
		if (tmp->num >= tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
int	ordenadob(t_stack *b)
{
	t_stack	*tmp;

	if (!b)
		return (1);
	tmp = b;
	while (tmp->next)
	{
		//printf("Comparando: %d con %d\n", tmp->num, tmp->next->num); 
		if (tmp->num <= tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int ft_pivote(t_stack *a)
{
	int suma = 0;
	int size = ft_lstsize(&a);
	while (a)
	{
		suma += a->num;
		a = a->next;
	}
	return(suma / size);
}
