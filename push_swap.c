/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:19:18 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/02/12 15:56:28 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*completeStack(char **argv);
int		posiciona(t_stack **a, int listsize);
int		posicionb(t_stack **b, int listsize, int numbr);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		sizea;
	int		sizeb;
	int		numbr;

	if (argc < 1)
		return (write(1, "\n", 1));
	else
	{
		a = completeStack(argv);
		b = NULL;
		sizea = ft_lstsize(&a);
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);
		sizeb = ft_lstsize(&b);
		ordena_b(&b);
		calculacoste(&a, &b);
		writeStack(a);
		writeStack(b);
		printf("----a---\n");
		numbr = posiciona(&a, sizea);
		writeStack(a);
		printf("---b----\n");
		posicionb(&b, sizeb, numbr);
		writeStack(b);
	}
}

int	posiciona(t_stack **a, int listsize)
{
	int		num;
	t_stack	*temp;

	temp = *a;
	num = encuentra(&temp);
	while (temp)
	{
		if (temp->num == num && temp->pos == 1)
			return (1);
		if (temp->num == num && temp->pos <= listsize / 2)
			ra(a);
		else
			rra(a);
		temp = *a;
	}
	return (num);
}

int	posicionb(t_stack **b, int listsize, int numbr)
{
	int		num;
	t_stack	*temp;

	temp = *b;
	num = encuentrb(temp, numbr);
	while (temp)
	{
		if (temp->num == num && temp->pos == 1)
			return (1);
		if (temp->num == num && temp->pos <= listsize / 2)
			rb(b);
		else
		{
			rrb(b);
		}
		temp = *b;
	}
	return (0);
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
