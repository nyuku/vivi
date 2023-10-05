/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_under_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:24:36 by angela            #+#    #+#             */
/*   Updated: 2023/09/04 11:01:00 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void    small_sorting(t_pushswap *ps)
{
	if (ps->number_numbers == 2)
		duo(ps);
	if (ps->number_numbers == 3)
		threesome(ps, 0);
	if (ps->number_numbers == 4)
		sorting_for(ps, 0);
	if (ps->number_numbers == 5)
		sorting_five(ps);
}

void    duo(t_pushswap *ps)
{
	if (ps->head_a->index != 1)
		swap(&(ps->head_a), ps);
}


//il y 5 cas à trier

//1-3-2 ->swap,rotate
//2-1-3 ->swap
//3-2-1 ->swap, r.rotate
//3-1-2 ->rotate
//2-3-1 ->r.rotate
void    threesome(t_pushswap *ps, int sorting_for)// sera 0 si seul, sinon pour compenser 3-4-5 de sorting 5 -> 1-2-3
{
	if (ps->head_a->index == (1 +sorting_for) && ps->head_a->next->index == (3+sorting_for) && ps->head_a->next->next->index == (2 +sorting_for))
	{
		swap(&(ps->head_a), ps);
		rotate_up(&(ps->head_a), ps);
	}
	else if (ps->head_a->index == (2 +sorting_for) && ps->head_a->next->index == (1 +sorting_for) && ps->head_a->next->next->index == (3 +sorting_for))
	{
		swap(&(ps->head_a), ps);
	}
	else if (ps->head_a->index == (3 +sorting_for) && ps->head_a->next->index == (2 +sorting_for) && ps->head_a->next->next->index == (1 +sorting_for))
	{
		swap(&(ps->head_a), ps);
		reverse_rotate(&(ps->head_a), ps);
	}
	else if (ps->head_a->index == (3 +sorting_for) && ps->head_a->next->index == (1 +sorting_for) && ps->head_a->next->next->index == (2 +sorting_for))
	{
		rotate_up(&(ps->head_a), ps);
	}
	else if (ps->head_a->index == (2 +sorting_for) && ps->head_a->next->index == (3 +sorting_for) && ps->head_a->next->next->index == (1 +sorting_for))
	{
		reverse_rotate(&(ps->head_a), ps);
	}
}

void    sorting_for(t_pushswap *ps, int five_sort)
{
	//t_node  *temp;
	//t_node *smallest;

	//temp = ps->head_a;
	t_node *prout;
	prout = last_node(ps->head_a);
	if (prout->index == 1)// si dernier == 1
		reverse_rotate(&(ps->head_a), ps);
	else
	{
		while ((five_sort == 0 && ps->head_a->index != 1) ||(five_sort == 1 && ps->head_a->index != 2)) // on cherche a mettre le n-1 au tout dessus
			rotate_up(&ps->head_a, ps);// max 3
	}
	push(&(ps->head_a), &(ps->head_b), ps);
	threesome(ps, 1);
	push(&(ps->head_b),&(ps->head_a), ps);
}

void    sorting_five(t_pushswap *ps)
{
	//t_node  *temp;
	//t_node *smallest;
	//t_node  *temp = ps->head_a;
	t_node *prout;
	prout = last_node(ps->head_a);
	if (prout->index == 1)// si dernier == 1
		reverse_rotate(&(ps->head_a), ps);
	else if((ps->head_a->index != 1))
	{
		while (ps->head_a->index != 1) // on cherche a mettre le n-1 au tout dessus
			rotate_up(&ps->head_a, ps);// max 4
	}
	push(&(ps->head_a), &(ps->head_b), ps);
	sorting_for(ps, 1);
	push(&(ps->head_b),&(ps->head_a), ps);
}