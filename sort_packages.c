/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_packages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:03:13 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/17 17:54:51 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_rev_sorted_unrotated(t_int_stack *stack, int min, int max)
{
	int	i;
	int	len;

	i = 0;
	len = stack_length(stack->num_list);
	while (stack->num_list[i] != NULL)
	{
		if (stack->num_list[i + 1] == NULL)
			break ;
		if ((*stack->num_list[i] < *stack->num_list[i + 1])
			&& !((*stack->num_list[i] == min)
				&& (*stack->num_list[i + 1] == max)))
			return (-1);
		i++;
	}
	if ((*stack->num_list[0] > *stack->num_list[len - 1])
		&& !((*stack->num_list[0] == max)
			&& (*stack->num_list[len - 1] == min)))
		return (-1);
	return (0);
}

static int	is_rev_sorted(t_int_stack *stack)
{
	int	i;

	i = 0;
	while (stack->num_list[i] != NULL)
	{
		if (stack->num_list[i + 1] == NULL)
			return (0);
		if ((*stack->num_list[i] < *stack->num_list[i + 1]))
			return (-1);
		i++;
	}
	return (0);
}

static void	rev_one_stack_swapping(t_int_stack *stack)
{
	int	i;
	int	min;
	int	max;

	min = *stack->num_list[min_num_index(stack)];
	max = *stack->num_list[max_num_index(stack)];
	while (is_rev_sorted_unrotated(stack, min, max) < 0)
	{
		i = 0;
		while (stack->num_list[i + 1] != NULL)
		{
			if (*stack->num_list[i] < *stack->num_list[i + 1]
				&& !(*stack->num_list[i] == min
					&& *stack->num_list[i + 1] == max))
				break ;
			i++;
		}
		best_rotate(stack, i);
		swap_one(stack);
	}
	i = max_num_index(stack);
	while (is_rev_sorted(stack) < 0)
		best_rotate(stack, i);
}

static void	sort_modulo_and_all(
	t_int_stack *a, t_int_stack *b, int len, int package_size)
{
	int	modulo;
	int	i;

	modulo = len % package_size;
	if (modulo != 0)
	{
		i = -1;
		while (++i < modulo)
			push(b, a);
		rev_one_stack_swapping(b);
		while (b->num_list[0] != NULL)
			push(a, b);
	}
	divide_sort_and_fusion(a, b);
}

void	sort_packages(t_int_stack *a, t_int_stack *b)
{
	int	stack_len;
	int	package_size;
	int	packages_n;
	int	i;

	stack_len = stack_length(a->num_list);
	package_size = 20;
	packages_n = (stack_len / package_size);
	if (is_sorted(a) < 0)
	{
		while (packages_n--)
		{
			i = -1;
			while (++i < package_size)
				push(b, a);
			rev_one_stack_swapping(b);
			while (b->num_list[0] != NULL)
				push(a, b);
			i = -1;
			while (++i < package_size)
				rotate_one(a);
		}
		sort_modulo_and_all(a, b, stack_len, package_size);
	}
}
