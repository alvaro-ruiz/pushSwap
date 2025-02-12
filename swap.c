/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:00:50 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/01/30 15:24:35 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	sa(t_stack *a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_stack *b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}
