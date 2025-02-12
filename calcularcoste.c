/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcularcoste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:55:23 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/02/12 15:32:58 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	costeposicion(t_stack **tmpa, int size);
void	numerocercano(t_stack **tmpa, t_stack **tmp, t_stack **nbr);

void	calculacoste(t_stack **a, t_stack **b)
{
	int		sizea;
	int		sizeb;
	t_stack	*nbr;
	t_stack	*tmp;
	t_stack	*tmpa;

	sizea = ft_lstsize(a);
	sizeb = ft_lstsize(b);
	tmpa = *a;
	while (tmpa)
	{
		tmp = *b;
		costeposicion(&tmpa, sizea);
		numerocercano(&tmpa, &tmp, &nbr);
		if (nbr->pos <= sizeb / 2)
			tmpa->cost = tmpa->cost + nbr->pos;
		else
			tmpa->cost = tmpa->cost + sizeb - nbr->pos;
		if (nbr->num > tmpa->num)
			tmpa->cost = tmpa->cost + 1;
		tmpa = tmpa->next;
	}
}

void	costeposicion(t_stack **tmpa, int size)
{
	if ((*tmpa)->pos <= size / 2)
		(*tmpa)->cost = (*tmpa)->cost + (*tmpa)->pos;
	else
		(*tmpa)->cost = (*tmpa)->cost + (size - (*tmpa)->pos) + 2;
}

void	numerocercano(t_stack **tmpa, t_stack **tmp, t_stack **nbr)
{
	int	diferencia;
	int	num;

	num = 0;
	diferencia = -1;
	while (*tmp)
	{
		diferencia = (*tmp)->num - (*tmpa)->num;
		if (diferencia < 0)
			diferencia = diferencia * -1;
		if (num == 0 || diferencia < num)
		{
			num = diferencia;
			(*nbr) = (*tmp);
		}
		(*tmp) = (*tmp)->next;
	}
}

int	encuentra(t_stack **tmpa)
{
	int	costmenor;
	int	num;

	costmenor = (*tmpa)->cost;
	num = (*tmpa)->num;
	while (*tmpa)
	{
		if (costmenor > (*tmpa)->cost)
		{
			num = (*tmpa)->num;
			costmenor = (*tmpa)->cost;
		}
		*tmpa = (*tmpa)->next;
	}
	return (num);
}

int	encuentrb(t_stack *tmpb, int numbr)
{
	int	diferencia;
	int	num;

	num = 0;
	diferencia = -1;
	while (tmpb)
	{
		diferencia = tmpb->num - numbr;
		if (diferencia < 0)
			diferencia = diferencia * -1;
		if (num == 0 || diferencia < num)
			num = diferencia;
		tmpb = tmpb->next;
	}
	return (num);
}
