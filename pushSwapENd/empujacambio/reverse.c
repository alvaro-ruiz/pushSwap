/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:00:40 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:55 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = ft_lstlast_del(*stack);
	last = ft_lstlast(*stack);
	tmp->next = NULL;
	ft_stack_poss(*stack, 1);
	last->next = *stack;
	last->pos = 1;
	*stack = last;
}

void	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	reverse(a);
}

void	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	reverse(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	reverse(a);
	reverse(b);
}
