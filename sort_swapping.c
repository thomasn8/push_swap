/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swapping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:31:02 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 17:13:56 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_stack_swapping(t_int_stack *a)
{
	int	i;
	int	min;
	int	max;

	min = *a->num_list[min_num_index(a)];
	max = *a->num_list[max_num_index(a)];
	while (is_sorted_unrotated(a, min, max) < 0)
	{
		i = 0;
		while (a->num_list[i + 1] != NULL)
		{
			if (*a->num_list[i] > *a->num_list[i + 1]
				&& !(*a->num_list[i] == max && *a->num_list[i + 1] == min))
				break ;
			i++;
		}
		best_rotate(a, i);
		swap_one(a);
	}
	i = min_num_index(a);
	while (is_sorted(a) < 0)
		best_rotate(a, i);
}
