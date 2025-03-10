/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:22:31 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/10 17:25:13 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_Stack
{
	int				num;
	int				pos;
	int				cost;
	struct s_Stack	*target;
	struct s_Stack	*next;
}	t_stack;

typedef struct s_Conroller
{
	int				rr;
	int				cambios;
}	t_conroller;

t_stack	*ft_stacknew(int content, int pos);
int		ft_lstadd_back(t_stack **lst, int num, int poss);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
void	write_stack(t_stack *stack, int target);
void	ft_stack_poss(t_stack *lst, int num);
int		ft_stackadd_back(t_stack **lst, t_stack *last);
t_stack	*ft_lstlast_del(t_stack *lst);
int		ft_lstsize(t_stack **lst);
t_conroller	*ft_controller();

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

int		ordena_b(t_stack **a);
int		ordena_a(t_stack **a);
int		ordenado(t_stack *a);
void	calculacoste(t_stack **a, t_stack **b);

void ft_find_target(t_stack **a, t_stack **b);

int		encuentrb(t_stack *tmpa);
t_stack	*encuentra_target(t_stack *tmp, int numbr);
#endif