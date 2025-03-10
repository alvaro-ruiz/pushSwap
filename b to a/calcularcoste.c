/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcularcoste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:55:23 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/03 17:28:45 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_cost_a(t_stack *a, t_stack *num) {
    int size = ft_lstsize(&a);
    int cost = 0;
    t_stack *tmp = a;

    while (tmp) {
        if (tmp->num == num->num)
            break;
        cost++;
        tmp = tmp->next;
    }

    if (cost > size / 2) {
        cost = size - cost;
    }

    return cost;
}

int calculate_cost_b(t_stack *b, t_stack *num) {
    int size = ft_lstsize(&b);
    int cost = 0;
    t_stack *tmp = b;

    while (tmp) {
        if (tmp->num == num->num)
            break;
        cost++;
        tmp = tmp->next;
    }
    if (cost > size / 2) {
        cost = size - cost;
    }
    return cost;
}

void calculacoste(t_stack **a, t_stack **b) {
    t_stack *tmp_a = *a;
    t_stack *tmp_b = *b;

    while (tmp_b) {
        int cost_a = calculate_cost_a(*a, tmp_a);
        int cost_b = calculate_cost_b(*b, tmp_b);

        tmp_b->cost = cost_a + cost_b;
        tmp_b = tmp_b->next;
    }
}

/*void	calculopotencial(t_stack *stack)
{
	int	size;

	size = ft_lstsize(&stack);
	while (stack)
	{
		stack->cost = 0;
		if ((stack)->pos <= size / 2 + 1)
			stack->cost += stack->pos;
		else
			stack->cost += (size - stack->pos) + 1;
		stack = stack->next;
	}
}

void	addcost(t_stack *tmpa, t_stack *tmpb)
{
	while (tmpb)
	{
		tmpb->cost += encuentra(tmpa, tmpb->num)->cost;
		tmpb = tmpb->next;
	}
}

void	calculacoste(t_stack **a, t_stack **b)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = *a;
	tmpb = *b;
	calculopotencial(tmpa);
	calculopotencial(tmpb);
	addcost(tmpa, tmpb);
	printf("coste\n");
	printf("----a----\n");
	writeStack(*a);
	printf("----b----\n");
	writeStack(*b);
}

Estaba loco por verte
Deseoso por tenerte
Quiero volver a su lado
No importa que diga la gente

Le juro señora nunca le fallé

Decían que por ser menor que usted, yo no la quería
Que no era amor solo interés, y aquí estoy todavía
Y aunque pase el tiempo lo sabes bien
Que soy aquel chico que te hizo sentir mujer
Siendo mayor que yo usted

Señora usted me gusta tanto igual que el primer día
Bienvenida a la tercera dinastia
Se juntaron los que to'el mundo quería
Para cumplir toditas sus fantasías

Con esa experiencia que usted me ha conquistado
Me tiene loco, me tiene enamorado
Y esa cinturita como que no ha cambiado
Y esta noche la quiero tener

Allá en mi cama
Dos cuerpos calenta'o, prendio en llamas
Que el ron que dure hasta las 3 de la mañana
Yo forever papa, tu forever mama

Ay malvada
Con mente de perversa
Como acelera cuando pone la reversa
Choca con el hunter cazando la presa
No baje el fronte vamo a matarnos

Que la quiero mayor que yo, que yo
Que me de calor, que me de, de su amor
Me eduque en experiencia, me deje loco
Me lleve a la cama y me haga alucinar

Que la quiero mayor que yo, que yo
Que me de calor, que me de, de su amor
Me eduque en experiencia, me deje loco
Me lleve a la cama y me haga alucinar

Lunes a viernes tiene novio, pero el sabado lo deja
Aparece el domingo con la cara de penweh'
Ella se viste cara y el tipo se acompleja
El tiguere es su favorito me lo dijo en la oreja

Señora mía, saludable, rica, 0 calorias
No has cambiado en nada tu sigues de reposteria
Quiero besarte de nuevo, me gustaría
Hay una sorpresa de victoria: Tú me la modelarias

Ese cuerpo no ha cambiado me tienes hipnotizado
Siempre fina, maquillada, tremendo calzado
Recordemos el pasado ya yo estoy desesperado
Completemos lo que no hemos terminado

Y que salvaje, de tinker bell el tatuaje
Cuando esta sola en su casa me llama pa' que trabaje
La monto en mi viaje ella quiere cangrinaje
No tiene ropa interior debajo del traje

Decian que por ser menor que usted
Yo no la quería
Que no era amor solo interes
Y aquí estoy todavía
Y aunque pase el tiempo lo sabes bien, que soy aquel
Chico que te hizo sentir mujer
Siendo mayor que yo usted

Y a mí me gusta la fruta madura que se deja comer
Cuando yo te pele ahí, ahí te voy a morder
Que bien tú te conservas haces que mi sangre hierba
La mujer es como el vino y tú eres la mejor reserva

Quiere que le diga, quiere que le diga dale mami enseñame
Quiere que le diga que en la cama usted es la que sabe
Dame cariñito corazón, dame cariñito corazón
No hay hombre que la dome cuando ella aprieta

Auu auu me puse salvaje
Auu auu aguanta el voltaje
Auu auu sacudeme ese motete
La yegua que pide fuete se lo damo' pa' que respete

Me tiene enloquecio, estoy convencio
Que usted se va conmigo aunque me busque un lío
Yo no te obligo ma, si yo te sigo
Tranquila que de aquí nos vamos encendio

Yo sé que arrepentido no me quedare
Entre mis sábanas te encontraré
Sabes que yo soy el hombre, que más te conoce
Siendo tu mayor que yo

Que la quiero mayor que yo, que yo
Que me de calor, que me de, de su amor
Me eduque en experiencia, me vuelve loco
Me lleve a la cama y me haga alucinar

Que la quiero mayor que yo, que yo
Que me de calor, que me de, de su amor
Me eduque en experiencia, me deje loco
Me lleve a la cama y me haga alucinar (fuimo)

Quiere que le diga, quiere que le diga dale mami enseñame
Quiere que le diga que en la cama usted es la que sabe
Dame cariñito corazón, dame cariñito corazón
No hay hombre que la dome cuando ella aprieta

Auu auu me puse salvaje
Auu auu aguanta el voltaje
Auu auu sacudeme ese motete
La yegua que pide fuete se lo damo' pa' que respete

void	costeposicion(t_stack **tmpa, int size);
void	numerocercano(t_stack *tmpa, t_stack *tmpb, t_stack **nbr);

void	calculacoste(t_stack **a, t_stack **b)
{
	int		sizea;
	int		sizeb;
	t_stack	*tmpa;
	t_stack	*tmpb;

	sizea = ft_lstsize(b);
	sizeb = ft_lstsize(a);
	tmpa = *b;
	tmpb = *a;
	while (tmpa)
	{
		tmpa->cost = 0;
		costeposicion(&tmpa, sizea);
		numerocercano(tmpa, tmpb, &tmpa);
		if (tmpa->num > tmpb->num)
			tmpa->cost += 1;
		tmpa = tmpa->next;
	}
}

void	costeposicion(t_stack **tmpa, int size)
{
	if ((*tmpa)->pos <= size / 2)
		(*tmpa)->cost += (*tmpa)->pos - 1;
	else
		(*tmpa)->cost += (size - (*tmpa)->pos) + 1;
}

void	numerocercano(t_stack *tmpa, t_stack *tmpb, t_stack **nbr)
{
	int	diferencia;
	int	diferenciaMenor;
	int	costmenor;
	int	num;

	diferenciaMenor = 1232323434;
	while (tmpb)
	{
		diferencia = abs(tmpb->num - tmpa->num);
		if (diferencia < diferenciaMenor)
		{
			diferenciaMenor = diferencia;
			*nbr = tmpb;
		}
		tmpb = tmpb->next;
	}
}*/
// Busca en el stack desodenado el que tiene menor coste
int	encuentrb(t_stack *tmpb)
{
	int	costmenor;
	int	num;

	if (!tmpb)
		return (-1);
	costmenor = tmpb->cost;
	num = tmpb->num;
	while (tmpb)
	{
		if (costmenor > tmpb->cost)
		{
			num = tmpb->num;
			costmenor = tmpb->cost;
		}
		tmpb = tmpb->next;
	}
	return (num);
}

//Busca el numero target del int que se le pasa
t_stack	*encuentra(t_stack *tmp, int numbr)
{
	int		diferencia;
	int		diferenciaMenor;
	t_stack	*num;

	if (!tmp)
		return (tmp);
	num = tmp;
	diferenciaMenor = tmp->num - numbr;
	if (diferenciaMenor < 0)
		diferenciaMenor = -diferenciaMenor;
	tmp = tmp->next;
	while (tmp)
	{
		diferencia = tmp->num - numbr;
		if (diferencia < 0)
			diferencia = -diferencia;
		if (diferencia < diferenciaMenor)
		{
			diferenciaMenor = diferencia;
			num = tmp;
		}
		tmp = tmp->next;
	}
	return (num);
}
