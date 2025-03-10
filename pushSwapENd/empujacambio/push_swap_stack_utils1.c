/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:43:24 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/10 17:25:21 by aruiz-bl         ###   ########.fr       */
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
		printf("%d,\n", tmp_a->target->num);
		tmp_a = tmp_a->next;
	}
}
