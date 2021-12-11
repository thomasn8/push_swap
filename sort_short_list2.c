/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_list2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:38:27 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 17:15:21 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min2_num_index(t_int_stack *stack)
{
	int	**list;
	int	i;
	int	min;
	int	min2;

	list = stack->num_list;
	i = -1;
	min = 0;
	while (list[++i] != NULL)
	{
		if (*list[i] < *list[min])
			min = i;
	}
	i = -1;
	if (min != 0)
		min2 = 0;
	else
		min2 = 1;
	while (list[++i] != NULL)
	{
		if (*list[i] > *list[min] && *list[i] < *list[min2])
			min2 = i;
	}
	return (min2);
}

static void	rev_sort_2num(t_int_stack *stack)
{
	if (*stack->num_list[0] < *stack->num_list[1])
		swap_one(stack);
}

void	sort_5num(t_int_stack *a, t_int_stack *b)
{
	int	min;
	int	min_num;
	int	min2;
	int	min2_num;

	min = min_num_index(a);
	min_num = *a->num_list[min];
	min2 = min2_num_index(a);
	min2_num = *a->num_list[min2];
	while (**a->num_list != min_num && **a->num_list != min2_num)
		rotate_one(a);
	push(b, a);
	while (**a->num_list != min_num && **a->num_list != min2_num)
		rotate_one(a);
	push(b, a);
	sort_3num(a);
	rev_sort_2num(b);
	push(a, b);
	push(a, b);
}
