/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:00:47 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/01 11:48:05 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	tmp->next = NULL;
	tmp->cost = 0;
	tmp->pos = last->pos + 1;
	last->next = tmp;
	ft_stack_poss(*stack, -1);
}

void	ra(t_stack **a, int *movement)
{
	rotate(a);
	(*movement)++;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b, int *movement)
{
	rotate(b);
	(*movement)++;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int *movement)
{
	write(1, "rr\n", 3);
	(*movement)++;
	rotate(a);
	rotate(b);
}
