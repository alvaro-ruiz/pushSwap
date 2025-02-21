/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:19:18 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/02/21 16:13:04 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*completeStack(char **argv);
int		posiciona(t_stack **a, int num);
int		posicionb(t_stack **b, int numB);
int		posicionado(t_stack **a, t_stack **b, t_conroller *controller);
void	reordenab(t_stack **b, 	t_conroller *controller);

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_conroller *controller;

	if (argc < 1)
		return (write(1, "\n", 1));
	else
	{
		controller = ft_controller();
		a = completeStack(argv);
		b = NULL;
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);
		ordena_b(&b);
		while (a)
		{
			calculacoste(&a, &b);
			if (posicionado(&a, &b, controller))
			{
				pb(&a, &b);
				if (b->num < b->next->num)
					sb(b);
				reordenab(&b, controller);
			}
		}
		while (b)
		{
			pa(&a, &b);
		}
		printf("----a---\n");
		writeStack(a);
		printf("---b----\n");
		writeStack(b);
	}
}

void	reordenab(t_stack **b, t_conroller *controller)
{
	int	i;

	i = 0;
	if (controller->rr == 0)
	{
		while (i < controller->cambios)
		{
			rb(b);
			i++;
		}
	}
	else
		while (i < controller->cambios)
		{
			rrb(b);
			i++;
		}
}

int	posicionado(t_stack **a, t_stack **b, t_conroller *controller)
{
	int		aa;
	int		bb;
	t_stack	*tmp;
	int		numA;
	int		numB;

	tmp = (*a);
	numA = encuentra(&tmp);
	tmp = (*b);
	numB = encuentrb(tmp, numA);
	controller->cambios = 0;
	while (1)
	{
		aa = posiciona(a, numA);
		bb = posicionb(b, numB);
		if (aa == 0 && bb == 0)
		{
			rr(a, b);
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 1 && bb == 1)
		{
			rrr(a, b);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 0 && bb == 1)
		{
			ra(a);
			rrb(b);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 1 && bb == 0)
		{
			rra(a);
			rb(b);
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 1 && bb == 2)
			rra(a);
		else if (bb == 1 && aa == 2)
		{
			rrb(b);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 0 && bb == 2)
			ra(a);
		else if (aa == 2 && bb == 0)
		{
			rb(b);
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
