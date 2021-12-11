/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:13:14 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 12:31:32 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	search_push_rotate_getback(t_int_stack *stack_a, t_int_stack *stack_b, int min, int max)
{
	int i;

	while (is_sorted_unrotated(stack_a, min, max) < 0)
	{
		i = 0;
		
		// swap si a[0] > a[1] 
		// et que a[0] et a[1] ne sont pas max et min (les seuls qui peuvent se suivre dans le mauvais ordre)
		if(!((*stack_a->num_list[i] == max) && (*stack_a->num_list[i + 1] == min)))
			sort_2num(stack_a);
		// check le tri, break si la list est déjà triée
		if(is_sorted(stack_a) == 0)
			break;
		
		// avance jusqu'au prochain num à trier
		// => prochain num supérieur à son suivant (n'étant pas max et min)
		while ((stack_a->num_list[i + 1] != NULL 
			&& *stack_a->num_list[i + 1] > *stack_a->num_list[i]) 
			|| ((*stack_a->num_list[i] == max) 
			&& (*stack_a->num_list[i + 1] == min)))
			i++;
		// si on est à la fin, check le tri, break si la list est triée
		if ((stack_a->num_list[i + 1] == NULL) 
			&& (is_sorted_unrotated(stack_a, min, max) == 0))
			break;

		// monte ce num en haut de a et le pousse sur b
		// (en tournant du côté le plus près du début de la pile)
		best_rotate(stack_a, i);
		push(stack_b, stack_a);
		
		i = 0;
		while (*stack_b->num_list[0] > *stack_a->num_list[i] 
			&& stack_a->num_list[i] != NULL 
			&& !(*stack_b->num_list[0] == max && *stack_a->num_list[i] == min))
		{
			i++;
		}
		best_rotate(stack_a, i);
		push(stack_a, stack_b);
	}
}

// a chaque loop, trie le premier num mal ordonné sur a :
// cherche num, push num sur b, rotate a jusqu'à l'endroit où réinsérer num, et push sur a
void	insertion_sort(t_int_stack *stack_a, t_int_stack *stack_b)
{
	int min;
	int max;

	min = *stack_a->num_list[min_num_index(stack_a)];
	max = *stack_a->num_list[max_num_index(stack_a)];
	// trie la pile
	search_push_rotate_getback(stack_a, stack_b, min, max);

	// fait tourner la pile jusqu'a avoir min en a[0] et max en a[end]
	min = min_num_index(stack_a);
	while (is_sorted(stack_a) < 0)
		best_rotate(stack_a, min);
}
