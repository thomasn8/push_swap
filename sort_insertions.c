/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:13:14 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 13:00:31 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	search_push_rotate_getback(t_int_stack *stack_a, t_int_stack *stack_b, int min, int max)
{
	int i;

	while (is_sorted_unrotated(stack_a, min, max) < 0)
	{
		i = 0;
		
		if(!((*stack_a->num_list[i] == max) && (*stack_a->num_list[i + 1] == min)))
			sort_2num(stack_a);
		if(is_sorted(stack_a) == 0)
			break;
		while ((stack_a->num_list[i + 1] != NULL 
			&& *stack_a->num_list[i + 1] > *stack_a->num_list[i]) 
			|| ((*stack_a->num_list[i] == max) 
			&& (*stack_a->num_list[i + 1] == min)))
			i++;
		if ((stack_a->num_list[i + 1] == NULL) 
			&& (is_sorted_unrotated(stack_a, min, max) == 0))
			break;
		best_rotate(stack_a, i);
		push(stack_b, stack_a);
		i = 0;
		while (*stack_b->num_list[0] > *stack_a->num_list[i] 
			&& stack_a->num_list[i] != NULL 
			&& !(*stack_b->num_list[0] == max && *stack_a->num_list[i] == min))
			i++;
		best_rotate(stack_a, i);
		push(stack_a, stack_b);
	}
}

void	insertion_sort(t_int_stack *stack_a, t_int_stack *stack_b)
{
	int min;
	int max;

	min = *stack_a->num_list[min_num_index(stack_a)];
	max = *stack_a->num_list[max_num_index(stack_a)];
	search_push_rotate_getback(stack_a, stack_b, min, max);
	min = min_num_index(stack_a);
	while (is_sorted(stack_a) < 0)
		best_rotate(stack_a, min);
}
