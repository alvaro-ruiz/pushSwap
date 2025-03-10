/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:19:18 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/04 16:48:42 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*completeStack(char **argv);
int		posiciona(t_stack **a, int num);
int		posicionado(t_stack **a, t_stack **b, t_conroller *controller, int *movement);
void	reordenab(t_stack **a, t_conroller *controller, int *movement);
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
		printf("----a----\n");
		writeStack(a);
		printf("----b----\n");
		writeStack(b);
		while (ordenado(a) != 1)
		{
			if (ft_lstsize(&a) == 3)
			{
				ordena_a(&a, &movement);
				break;
			}
			pb(&a, &b, &movement);
		}
		while (b)
		{
			printf("inicio\n");
			printf("----a----\n");
			writeStack(a);
			printf("----b----\n");
			writeStack(b);
			calculacoste(&a, &b);
			if (posicionado(&a, &b, controller, &movement))
			{
				pa(&a, &b, &movement);
				printf("num1; %d, num2; %d\n", a->num , a->next->num);
				if (a->num > a->next->num)
					sa(a, &movement);
				if (ordenado(a) == 0)
					reordenab(&a, controller, &movement);
				printf("%d\n", ordenado(a));
			}
		}
		printf("----a----\n");
		writeStack(a);
		printf("----b----\n");
		writeStack(b);
		printf("Movements; %d\n", movement);
		printf("%d\n", ordenado(a));
	}
}

void	reordenab(t_stack **a, t_conroller *controller, int *movement)
{
	int	i;

	i = 0;
	if (controller->rr == 1)
	{
		while (i <= controller->cambios)
		{
			ra(a, movement);
			i++;
		}
	}
	else
	{
		while (i < controller->cambios)
		{
			rra(a, movement);
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

	numB = encuentrb(*b);
	numA = encuentra(*a, numB)->num;
	controller->cambios = 0;
	controller->rr = 0;

		bb = posiciona(b, numB);
		aa = posiciona(a, numA);
		if (aa == 0 && bb == 0)
		{
			rrr(a, b, movement);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 1 && bb == 1)
		{
			rr(a, b, movement);
			controller->rr = 0;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 0 && bb == 1)
		{
			rra(a, movement);
			rb(b, movement);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 1 && bb == 0)
		{
			ra(a, movement);
			rrb(b, movement);
			controller->rr = 0;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 1 && bb == 2)
		{
			ra(a, movement);
			controller->rr = 0;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 2 && bb == 1)
			rb(b, movement);
		else if (aa == 0 && bb == 2)
		{
			rra(a, movement);
			controller->rr = 1;
			controller->cambios = controller->cambios + 1;
		}
		else if (aa == 2 && bb == 0)
			rrb(b, movement);
		else if (aa == 2 && bb == 2)
			return (1);
	return (0);
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
