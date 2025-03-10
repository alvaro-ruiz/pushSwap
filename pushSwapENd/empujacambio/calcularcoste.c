/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcularcoste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:55:23 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/10 17:47:25 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_cost_a(t_stack *a) {
    int size = ft_lstsize(&a);
    int cost = 0;
    t_stack *tmp = a;

    while (tmp) {
        if (tmp->pos == 1)
            break;
        cost++;
        tmp = tmp->next;
    }

    if (cost > size / 2) {
        cost = size - cost;
    }

    return cost;
}

int calculate_cost_b(t_stack *b, t_stack *num) {
    int size = ft_lstsize(&b);
    int cost = 0;
    t_stack *tmp = b;

    while (tmp) {
        if (tmp->num == num->num)
            break;
        cost++;
        tmp = tmp->next;
    }
    if (cost > size / 2) {
        cost = size - cost;
    }
    return cost;
}

void calculacoste(t_stack **a, t_stack **b) {
    t_stack *tmp_a = *a;

    while (tmp_a) {
        int cost_a = calculate_cost_a(tmp_a);
        int cost_b = calculate_cost_b(*b, tmp_a->target);
		printf("");

        tmp_a->cost = cost_a + cost_b;
        tmp_a = tmp_a->next;
    }
}
// Busca en el stack desodenado el que tiene menor coste
int	encuentrb(t_stack *tmpb)
{
	int	costmenor;
	int	num;

	if (!tmpb)
		return (-1);
	costmenor = tmpb->cost;
	num = tmpb->num;
	while (tmpb)
	{
		if (costmenor > tmpb->cost)
		{
			num = tmpb->num;
			costmenor = tmpb->cost;
		}
		tmpb = tmpb->next;
	}
	return (num);
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
