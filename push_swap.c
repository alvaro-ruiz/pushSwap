/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:19:18 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/02/18 16:58:39 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*completeStack(char **argv);
int		posiciona(t_stack **a, int num);
int		posicionb(t_stack **b, int numB);
int	posicionado(t_stack **a, t_stack **b);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 1)
		return (write(1, "\n", 1));
	else
	{
		a = completeStack(argv);
		b = NULL;
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);
		ordena_b(&b);
		calculacoste(&a, &b);
		writeStack(a);
		writeStack(b);
		posicionado(&a, &b);
		printf("----a---\n");
		writeStack(a);
		printf("---b----\n");
		writeStack(b);
	}
}

int	posicionado(t_stack **a, t_stack **b)
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
	while (1 == 1)
	{
		aa = posiciona(a, numA);
		bb = posicionb(b, numB);
		if (aa == 1 && aa == bb)
			rrr(a, b);
		if (aa == 0 && aa == bb)
			rr(a, b);
		if (aa == 1 && bb == 0)
		{
			ra(a);
			rrb(b);
		}
		else if (aa == 0 && bb == 1)
		{
			rra(a);
			rb(b);
		}
		else if (aa == 2 && aa == 2)
			return (1);
	}
}

int	posiciona(t_stack **a, int num)
{
	t_stack	*temp;

	temp = *a;
	if (temp->num == num && temp->pos == 1)
		return (1);
	if (temp->num == num && temp->pos <= ft_lstsize(a) / 2)
		return (0);
	else
		return (2);
}

int	posicionb(t_stack **b, int numB)
{
	t_stack	*temp;

	temp = *b;
	if (temp->num == numB && temp->pos == 1)
		return (1);
	if (temp->num == numB && temp->pos <= ft_lstsize(b) / 2)
		return (0);
	else
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
