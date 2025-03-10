/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:00:54 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:30 by aruiz-bl         ###   ########.fr       */
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

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a,b);
	write(1, "pb\n", 3);
}
