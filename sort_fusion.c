/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:37:06 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/12 20:20:42 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_stack(t_int_stack *a, t_int_stack *b, int len)
{
	int	min;
	int	max;

	min = *a->num_list[min_num_index(a)];
	max = *a->num_list[max_num_index(a)];
	len = len / 2;
	while (len--)
	{	
		if (*a->num_list[0] == min || *a->num_list[0] == max)
		{
			rotate_one(a);
			len++;
		}
		else
			push(b, a);
	}
}

static void	parallel_sort(t_int_stack *a, t_int_stack *b)
{
	int	min_a;
	int	max_a;
	int	min_b;
	int	max_b;

	min_a = *a->num_list[min_num_index(a)];
	max_a = *a->num_list[max_num_index(a)];
	min_b = *a->num_list[min_num_index(b)];
	max_b = *a->num_list[max_num_index(b)];
	while ((is_sorted_unrotated(a, min_a, max_a) < 0)
		&& (is_sorted_unrotated(b, min_b, max_b) < 0))
	{
		if ((*a->num_list[0] > *a->num_list[1])
			&& (*b->num_list[0] > *b->num_list[1])
			&& !(*a->num_list[0] == max_a && *a->num_list[1] == min_a)
			&& !(*b->num_list[0] == max_b && *b->num_list[1] == min_b))
			swap_both(a, b);
		if (*a->num_list[0] > *a->num_list[1]
			&& !(*a->num_list[0] == max_a && *a->num_list[1] == min_a))
			swap_one(a);
		if (*b->num_list[0] > *b->num_list[1]
			&& !(*b->num_list[0] == max_b && *b->num_list[1] == min_b))
			swap_one(b);
		rotate_both(a, b);
	}
}

static void	finish_sort(t_int_stack *a, t_int_stack *b, int len)
{
	int	min_a;
	int	max_a;
	int	min_b;
	int	max_b;

	min_a = *a->num_list[min_num_index(a)];
	max_a = *a->num_list[max_num_index(a)];
	min_b = *b->num_list[min_num_index(b)];
	max_b = *b->num_list[max_num_index(b)];
	if (is_sorted_unrotated(a, min_a, max_a) < 0)
	{
		if (len < 29)
			one_stack_swapping(a);
		else
			insertion_sort(a, b);
	}
	if (is_sorted_unrotated(b, min_b, max_b) < 0)
	{	
		if (len < 29)
			one_stack_swapping(b);
		else
			insertion_sort(b, a);
	}
}

void	divide_sort_and_fusion(t_int_stack *a, t_int_stack *b)
{
	int	len;
	int	i;

	if (is_sorted(a) < 0)
	{
		len = stack_length(a->num_list);
		divide_stack(a, b, len);
		parallel_sort(a, b);
		finish_sort(a, b, len);
		while (b->num_list[0] != NULL)
		{
			if ((*b->num_list[0] > *a->num_list[0])
				&& (*b->num_list[0] < *a->num_list[1]))
			{
				rotate_one(a);
				push(a, b);
			}
			else
				rotate_one(a);
		}
		i = min_num_index(a);
		while (is_sorted(a) < 0)
			best_rotate(a, i);
	}
}
