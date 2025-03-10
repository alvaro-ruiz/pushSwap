/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:19:18 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/10 17:46:21 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*completeStack(char **argv);
int		posiciona(t_stack **a, int num);
int		posicionado(t_stack **a, t_stack **b, t_conroller *controller);
void	reordenab(t_stack **a, t_conroller *controller);
int		ordenado(t_stack *b);

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_conroller	*controller;
	int			size;

	if (argc < 1)
		return (write(1, "\n", 1));
	else
	{
		controller = ft_controller();
		a = completeStack(argv);
		b = NULL;
		size = ft_lstsize(&a);
		if (ordenado(a) && size > 3)
			pb(&a, &b);
		if (ordenado(a) && size > 3)
			pb(&a, &b);
		if (ordenado(b) && ft_lstsize(&b) > 0)
			sb(b);
		while (ft_lstsize(&a) > 3 && !ordenado(a))
		{
			ft_find_target(&a, &b);
			calculacoste(&a, &b);
			pb(&a, &b);
		}
		ordena_a(&a);
		printf("----a----\n");
		write_stack(a, 0);
		printf("----b----\n");
		write_stack(b, 0);
		printf("%d\n", ordenado(a));
	}
}

void	reordenab(t_stack **a, t_conroller *controller)
{
	int	i;

	i = 0;
	if (controller->rr == 1)
	{
		while (i <= controller->cambios)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < controller->cambios)
		{
			rra(a);
			i++;
		}
	}
}

/*int	posicionado(t_stack **a, t_stack **b, t_conroller *controller)
{
	int	aa;
	int	bb;
	int	numA;
	int	numB;

	numB = encuentrb(*b);
	numA = encuentra(*a, numB)->num;
	controller->cambios = 0;
	controller->rr = 0;
	bb = posiciona(b, numB);
	aa = posiciona(a, numA);
	if (aa == 0 && bb == 0)
	{
		rrr(a, b);
		controller->rr = 1;
		controller->cambios = controller->cambios + 1;
	}
	else if (aa == 1 && bb == 1)
	{
		rr(a, b);
		controller->rr = 0;
		controller->cambios = controller->cambios + 1;
	}
	else if (aa == 0 && bb == 1)
	{
		rra(a);
		rb(b);
		controller->rr = 1;
		controller->cambios = controller->cambios + 1;
	}
	else if (aa == 1 && bb == 0)
	{
		ra(a);
		rrb(b);
		controller->rr = 0;
		controller->cambios = controller->cambios + 1;
	}
	else if (aa == 1 && bb == 2)
	{
		ra(a);
		controller->rr = 0;
		controller->cambios = controller->cambios + 1;
	}
	else if (aa == 2 && bb == 1)
		rb(b);
	else if (aa == 0 && bb == 2)
	{
		rra(a);
		controller->rr = 1;
		controller->cambios = controller->cambios + 1;
	}
	else if (aa == 2 && bb == 0)
		rrb(b);
	else if (aa == 2 && bb == 2)
		return (1);
	return (0);
}*/

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
			if (temp->pos <= size / 2 + 1)
				return (1);
			else
				return (0);
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
