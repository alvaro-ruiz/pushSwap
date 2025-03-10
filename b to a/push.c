/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:00:54 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/01 11:47:41 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **sale, t_stack **entra)
{
	t_stack	*tmp;

	if (!*entra)
	{
		*entra = ft_stacknew((*sale)->num, 1);
		*sale = (*sale)->next;
		ft_stack_poss(*sale, -1);
	}
	else
	{
		tmp = *sale;
		*sale = (*sale)->next;
		tmp->pos = 0;
		tmp->next = *entra;
		*entra = tmp;
		ft_stack_poss(*sale, -1);
		ft_stack_poss(*entra, +1);
	}
}

void	pa(t_stack **a, t_stack **b, int *movement)
{
	push(b, a);
	(*movement)++;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int *movement)
{
	push(a,b);
	(*movement)++;
	write(1, "pb\n", 3);
}
