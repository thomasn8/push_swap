/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swapping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:31:02 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 16:51:48 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_stack_swapping(t_int_stack *stack_a)
{
	int	i;
	int	min;
	int	max;

	min = *stack_a->num_list[min_num_index(stack_a)];
	max = *stack_a->num_list[max_num_index(stack_a)];
	while (is_sorted_unrotated(stack_a, min, max) < 0)
	{
		i = 0;
		while (stack_a->num_list[i + 1] != NULL)
		{
			if (*stack_a->num_list[i] > *stack_a->num_list[i + 1]
				&& !(*stack_a->num_list[i] == max && *stack_a->num_list[i + 1] == min))
				break ;
			i++;
		}
		best_rotate(stack_a, i);
		swap_one(stack_a);
	}
	i = min_num_index(stack_a);
	while (is_sorted(stack_a) < 0)
		best_rotate(stack_a, i);
}
