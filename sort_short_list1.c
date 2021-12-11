/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_list1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:57:08 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 13:01:11 by tnanchen         ###   ########.fr       */
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
	
	push(stack_b, stack_a);
	sort_3num(stack_a);
	max = max_num_index(stack_a);
	max_num = *stack_a->num_list[max];
	while (**stack_b->num_list > **stack_a->num_list && **stack_a->num_list != max_num)
		rotate_one(stack_a);
	if (**stack_b->num_list > max_num)
		rotate_one(stack_a);
	push(stack_a, stack_b);
	min = min_num_index(stack_a);
	best_rotate(stack_a, min);
}
