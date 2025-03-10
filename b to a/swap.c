/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:00:50 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/01 11:48:15 by aruiz-bl         ###   ########.fr       */
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

void	sa(t_stack *a, int *movement)
{
	write(1, "sa\n", 3);
	(*movement)++;
	swap(a);
}

void	sb(t_stack *b, int *movement)
{
	write(1, "sb\n", 3);
	(*movement)++;
	swap(b);
}

void	ss(t_stack *a, t_stack *b, int *movement)
{
	write(1, "ss\n", 3);
	(*movement)++;
	swap(a);
	swap(b);
}
