/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:43:24 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/11 17:00:05 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_find_target(t_stack **a, t_stack **b)
{
	t_stack *tmp_a = *a;
    t_stack *tmp_b;

	while (tmp_a)
	{
		tmp_b = *b;
		tmp_a->target = encuentra_target(tmp_b, tmp_a->num);
		tmp_a = tmp_a->next;
	}
}

//Busca el numero target del int que se le pasa
t_stack	*encuentra_target(t_stack *tmp, int numbr)
{
	int		diferencia;
	int		diferenciaMenor;
	t_stack	*num;

	if (!tmp)
		return (tmp);
	num = tmp;
	diferenciaMenor = tmp->num - numbr;
	if (diferenciaMenor < 0)
		diferenciaMenor = -diferenciaMenor;
	tmp = tmp->next;
	while (tmp)
	{
		diferencia = tmp->num - numbr;
		if (diferencia < 0)
			diferencia = -diferencia;
		if (diferencia < diferenciaMenor)
		{
			diferenciaMenor = diferencia;
			num = tmp;
		}
		tmp = tmp->next;
	}
	return (num);
}

// Mira si el numero que le pasamos por argumento esta en la primera posicion
int	posiciona(t_stack **a, int num)
{
	t_stack	*temp;
	int		size;

	temp = *a;
	size = ft_lstsize(a);
	while (temp)
	{
		if (temp->num == num && temp->pos != 1)
		{
			if (temp->pos <= size / 2 + 1)
				return (1);
			else
				return (0);
		}
		temp = temp->next;
	}
	return (2);
}

// Busca en el stack el nodo que tiene menor coste
t_stack	*ft_lower_cost(t_stack *stack)
{
	int	costmenor;
	t_stack	*temp;

	if (!stack)
		return (NULL);
	costmenor = stack->cost;
	temp = stack;
	while (stack)
	{
		if (costmenor > stack->cost)
		{
			temp = stack;
			costmenor = stack->cost;
		}
		stack = stack->next;
	}
	return (temp);
}
