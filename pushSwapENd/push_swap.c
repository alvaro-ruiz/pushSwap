/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:19:18 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/11 17:28:44 by aruiz-bl         ###   ########.fr       */
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
		if (size > 3)
			pb(&a, &b);
		if (size > 3)
			pb(&a, &b);
		if (ordenado(b) && ft_lstsize(&b) > 0)
			sb(b);
		while (ft_lstsize(&a) > 3)
		{
			ft_find_target(&a, &b);
			calculacoste(&a, &b);
			printf("----a----\n");
			write_stack(a, 0);
			printf("----b----\n");
			write_stack(b, 0);
			posicionado(&a, &b, controller);
			pb(&a, &b);
			if (b->num < b->next->num)
				sb(b);
			reordenab(&b, controller);
		}
		ordena_a(&a);
		ft_find_target(&b, &a);
		while (b)
		{
			pa(&a, &b);
		}
		printf("----a----\n");
		write_stack(a, 1);
		printf("----b----\n");
		write_stack(b, 1);
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

int	posicionado(t_stack **a, t_stack **b, t_conroller *controller)
{
	int		posicion_a;
	int		posicion_b;
	t_stack	*tmp;

	tmp = ft_lower_cost(*a);
	controller->cambios = 0;
	controller->rr = 0;
	while (1)
	{
		posicion_b = posiciona(b, tmp->target->num);
		posicion_a = posiciona(a, tmp->num);
		if (posicion_a == 0 && posicion_b == 0)
		{
			rrr(a, b);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (posicion_a == 1 && posicion_b == 1)
		{
			rr(a, b);
			controller->rr = 0;
			controller->cambios = controller->cambios + 1;
		}
		else if (posicion_a == 0 && posicion_b == 1)
		{
			rra(a);
			rb(b);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (posicion_a == 1 && posicion_b == 0)
		{
			ra(a);
			rrb(b);
			controller->rr = 0;
			controller->cambios = controller->cambios + 1;
		}
		else if (posicion_a == 1 && posicion_b == 2)
		{
			ra(a);
			controller->rr = 0;
			controller->cambios = controller->cambios + 1;
		}
		else if (posicion_a == 2 && posicion_b == 1)
			rb(b);
		else if (posicion_a == 0 && posicion_b == 2)
		{
			rra(a);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (posicion_a == 2 && posicion_b == 0)
			rrb(b);
		else if (posicion_a == 2 && posicion_b == 2)
			return (1);
	}
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
