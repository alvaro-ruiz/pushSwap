/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:19:18 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/01 11:46:54 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*completeStack(char **argv);
int		posiciona(t_stack **a, int num);
int		posicionb(t_stack **b, int numB);
int		posicionado(t_stack **a, t_stack **b, t_conroller *controller, int *movement);
void	reordenab(t_stack **b, t_conroller *controller, int *movement);
int		ordenado(t_stack *b);

/*Me tira pa' que yo la pruebe
Se pone olorosa y me gusta cómo huele
Instagram privado pa' que nadie la vele
Se puso bonita porque sabe que hoy se bebe
A portarse mal pa' sentirse bien
No quería fumar pero le dio al pen
Una Barbie pero no busca un Ken
Siempre le llego cuando dice "ven"
Pa' portarse mal se viste bien
Dice la verdad y a veces miente también
Apaga las notificaciones en el cel
Ella tiene lo suyo pero hoy quiere joder*/
int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_conroller	*controller;
	int			movement = 0;

	if (argc < 1)
		return (write(1, "\n", 1));
	else
	{
		controller = ft_controller();
		a = completeStack(argv);
		b = NULL;
		pb(&a, &b, &movement);
		pb(&a, &b, &movement);
		pb(&a, &b, &movement);
		ordena_b(&b, &movement);
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
		printf("Movements; %d", movement);
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

int	ordenado(t_stack *b)
{
	t_stack	*tmp;

	if (!b)
		return (1);
	tmp = b;
	while (tmp->next)
	{
		if (tmp->num < tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
