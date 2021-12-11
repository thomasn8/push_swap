/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_list1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:57:08 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 17:16:35 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2num(t_int_stack *stack)
{
	if (*stack->num_list[0] > *stack->num_list[1])
		swap_one(stack);
}

void	sort_3num(t_int_stack *stack)
{
	while (is_sorted(stack) < 0)
	{
		if (*stack->num_list[1] < *stack->num_list[2]
			&& *stack->num_list[0] > *stack->num_list[2])
			rotate_one(stack);
		sort_2num(stack);
		if (is_sorted(stack) < 0)
			rev_rotate_one(stack);
	}
}

void	sort_4num(t_int_stack *a, t_int_stack *b)
{
	int	min;
	int	max;
	int	max_num;

	push(b, a);
	sort_3num(a);
	max = max_num_index(a);
	max_num = *a->num_list[max];
	while (**b->num_list > **a->num_list
		&& **a->num_list != max_num)
		rotate_one(a);
	if (**b->num_list > max_num)
		rotate_one(a);
	push(a, b);
	min = min_num_index(a);
	best_rotate(a, min);
}
