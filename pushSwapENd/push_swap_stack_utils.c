/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:21:42 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/20 13:29:50 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int content, int pos)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = content;
	stack->cost = 0;
	stack->target = NULL;
	stack->pos = pos;
	stack->next = NULL;
	return (stack);
}

int	ft_lstadd_back(t_stack **lst, int num, int poss)
{
	t_stack	*tmp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->num = num;
	new->pos = poss;
	new->cost = 0;
	new->target = NULL;
	new->next = NULL;
	tmp = ft_lstlast(*lst);
	tmp->next = new;
	return (1);
}

void	ft_stack_poss(t_stack *lst, int num)
{
	while (lst != NULL)
	{
		lst->pos = lst->pos + num;
		lst = lst->next;
	}
}

// Devuelve el ultimo stack
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// Penultimo
t_stack	*ft_lstlast_del(t_stack *lst)
{
	t_stack *tmp;

	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		if (lst->next->next != NULL)
		{
			tmp = lst->next;
		}
		lst = lst->next;
	}
	return (tmp);
}

int	ft_lstsize(t_stack **lst)
{
	t_stack *last;
	if (!(*lst))
		return (0);
	last = ft_lstlast(*lst);
	return (last->pos);
}

// escribe el stack
void	write_stack(t_stack *stack, int target)
{
	while (stack != NULL)
	{
		if (target == 0)
			printf("digito: %ld , pos: %d , cost: %d\n", stack->num, stack->pos, stack->cost);
		else 
			printf("digito: %ld , pos: %d , cost: %d, target: %ld\n", stack->num, stack->pos, stack->cost, stack->target->num);
		//printf("%d, ", stack->num);
		stack = stack->next;
	}
	printf("\n");
}
