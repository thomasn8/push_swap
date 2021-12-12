/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:13:14 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 17:20:56 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	search_push_rotate_getback(
	t_int_stack *a, t_int_stack *b, int min, int max)
{
	int	i;

	while (is_sorted_unrotated(a, min, max) < 0)
	{
		i = 0;
		if (!((*a->num_list[i] == max) && (*a->num_list[i + 1] == min)))
			sort_2num(a);
		if (is_sorted(a) == 0)
			break ;
		while ((a->num_list[i + 1] != NULL
				&& *a->num_list[i + 1] > *a->num_list[i])
			|| ((*a->num_list[i] == max) && (*a->num_list[i + 1] == min)))
			i++;
		if ((a->num_list[i + 1] == NULL)
			&& (is_sorted_unrotated(a, min, max) == 0))
			break ;
		best_rotate(a, i);
		push(b, a);
		i = 0;
		while (*b->num_list[0] > *a->num_list[i] && a->num_list[i] != NULL
			&& !(*b->num_list[0] == max && *a->num_list[i] == min))
			i++;
		best_rotate(a, i);
		push(a, b);
	}
}

void	insertion_sort(t_int_stack *a, t_int_stack *b)
{
	int	min;
	int	max;

	min = *a->num_list[min_num_index(a)];
	max = *a->num_list[max_num_index(a)];
	search_push_rotate_getback(a, b, min, max);
	min = min_num_index(a);
	while (is_sorted(a) < 0)
		best_rotate(a, min);
}
