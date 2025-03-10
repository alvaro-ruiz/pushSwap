/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:19:18 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/10 16:02:40 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*completeStack(char **argv);
int		posiciona(t_stack **a, int num);
int		posicionb(t_stack **b, int numB);
int		posicionado(t_stack **a, t_stack **b, t_conroller *controller, int *movement);
void	reordenab(t_stack **b, t_conroller *controller, int *movement);

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_conroller	*controller;
	int			movement = 0;
	int			pivote;

	if (argc < 1)
		return (write(1, "\n", 1));
	else
	{
		controller = ft_controller();
		a = completeStack(argv);
		pivote = ft_pivote(a);
		b = NULL;
		if (!ordenado(a) && ft_lstsize(&a) > 3)
			pb(&a, &b, &movement);
		if (!ordenado(a) && ft_lstsize(&a) > 3)
			pb(&a, &b, &movement);
		if (!ordenado(a) && ft_lstsize(&a) > 3)
			pb(&a, &b, &movement);
		if (!ordenadob(b))
			ordena_b(&b, &movement);
		writeStack(a);
		writeStack(b);
		while (a)
		{
			calculacoste(&a, &b);
			if (posicionado(&a, &b, controller, &movement))
			{
				pb(&a, &b, &movement);
				if (b->num < b->next->num)
					sb(b, &movement);
				if (ordenado(b) == 0)
					reordenab(&b, controller, &movement);
			}
		}
		while (b)
			pa(&a, &b, &movement);
		writeStack(a);
		printf("Movements; %d\n", movement);
		printf("%d\n", ordenado(a));
		printf("%d", pivote);
	}
}

void	reordenab(t_stack **b, t_conroller *controller, int *movement)
{
	int	i;

	i = 0;
	if (controller->rr == 1)
	{
		while (i <= controller->cambios)
		{
			rb(b, movement);
			i++;
		}
	}
	else
	{
		while (i < controller->cambios)
		{
			rrb(b, movement);
			i++;
		}
	}
}

int	posicionado(t_stack **a, t_stack **b, t_conroller *controller, int *movement)
{
	int	aa;
	int	bb;
	int	numA;
	int	numB;

	numA = encuentra(*a);
	numB = encuentrb(*b, numA);
	controller->cambios = 0;
	controller->rr = 0;
	while (1)
	{
		aa = posiciona(a, numA);
		bb = posicionb(b, numB);
		if (aa == 0 && bb == 0)
		{
			rr(a, b, movement);
			controller->rr = 0;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 1 && bb == 1)
		{
			rrr(a, b, movement);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 0 && bb == 1)
		{
			ra(a, movement);
			rrb(b, movement);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 1 && bb == 0)
		{
			rra(a, movement);
			rb(b, movement);
			controller->rr = 0;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 1 && bb == 2)
			rra(a, movement);
		else if (aa == 2 && bb == 1)
		{
			rrb(b, movement);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 0 && bb == 2)
			ra(a, movement);
		else if (aa == 2 && bb == 0)
		{
			rb(b, movement);
			controller->rr = 0;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 2 && bb == 2)
			return (1);
	}
}

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
			if (temp->pos <= size / 2)
				return (0);
			else
				return (1);
		}
		temp = temp->next;
	}
	return (2);
}

int	posicionb(t_stack **b, int numB)
{
	t_stack	*temp;
	int		size;

	temp = *b;
	size = ft_lstsize(b);
	while (temp)
	{
		if (temp->num == numB && temp->pos != 1)
		{
			if (temp->pos <= size / 2)
				return (0);
			else
				return (1);
		}
		temp = temp->next;
	}
	return (2);
}

t_stack	*completeStack(char **argv)
{
	t_stack	*a;
	int		i;
	int		ok;

	i = 2;
	a = ft_stacknew(atoi(argv[1]), 1);
	while (argv[i])
	{
		ok = ft_lstadd_back(&a, atoi(argv[i]), i);
		if (!ok)
		{
			free(a);
			return (NULL);
		}
		i++;
	}
	return (a);
}
