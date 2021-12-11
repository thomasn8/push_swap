/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_list1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:57:08 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 01:59:04 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2num(t_int_stack *stack)
{
	if (*stack->num_list[0] > *stack->num_list[1])
		swap_one(stack);
}

void sort_3num(t_int_stack *stack)
{
	while (is_sorted(stack) < 0)
	{
		if (*stack->num_list[1] < *stack->num_list[2] && *stack->num_list[0] > *stack->num_list[2])
			rotate_one(stack);
		sort_2num(stack);
		if (is_sorted(stack) < 0)
			rev_rotate_one(stack);
	}
}

void sort_4num(t_int_stack *stack_a, t_int_stack *stack_b)
{
	int min;
	int max;
	int max_num;
	
	// pousse le 1er num de a sur b
	// puis tri les 3 num de a dans l'ordre
	push(stack_b, stack_a);
	sort_3num(stack_a);
	
	// tourne la pile tant que b[0] > nombres la pile a, 
	// et que a_max n'est pas passé en a[0] (empêche une loop infinie)
	// puis remet ce nombre sur la pile, au bon endroit
	max = max_num_index(stack_a);
	max_num = *stack_a->num_list[max];
	while (**stack_b->num_list > **stack_a->num_list && **stack_a->num_list != max_num)
		rotate_one(stack_a);
	if (**stack_b->num_list > max_num)
		rotate_one(stack_a);
	push(stack_a, stack_b);
	
	// ici la pile est ordonnée mais pas dans la bonne rotation
	// fait tourner la pile jusqu'a ce que le plus petit soit au début
	// pour pouvoir répéter la fonction sur une pile prête et partiellement triée
	min = min_num_index(stack_a);
	best_rotate(stack_a, min);
}
