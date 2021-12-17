/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_packages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:03:13 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/17 10:42:25 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* pseudo code
	// 1. push les 7 / 12 1er num sur b.
	// 2. trier b dans l'ordre inverse.
	// 3. push tous les num de b sur a.
	// 4. tourner a de 7 / 12 rotations.
	// 5. répéter le tout (stack_len / 7 ou stack_len / 12) fois
		// $modulo = stack_len % 7 ou stack_len % 12
		// push $modulo num sur b
		// trier b dans l'ordre inverse.
		// push tous les num de b sur a.
	// 6. final sort : sort_fusion
*/

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

static void	rev_one_stack_swapping(t_int_stack *a)
{
	int	i;
	int	min;
	int	max;

	min = *a->num_list[min_num_index(a)];
	max = *a->num_list[max_num_index(a)];
	while (is_rev_sorted_unrotated(a, min, max) < 0)
	{
		i = 0;
		while (a->num_list[i + 1] != NULL)
		{
			if (*a->num_list[i] < *a->num_list[i + 1]
				&& !(*a->num_list[i] == min && *a->num_list[i + 1] == max))
				break ;
			i++;
		}
		best_rotate(a, i);
		swap_one(a);
	}
	print_stack(a, 'a');
	i = max_num_index(a);
	while (is_rev_sorted(a) < 0)
		best_rotate(a, i);
}

void	sort_packages(t_int_stack *a, t_int_stack *b)
{
	int package_size;
	int i;

	package_size = 7;
	i = 0;
	if (is_sorted(a) < 0)
	{
		while (i < package_size)
			push(b, a);
	}

	// (void) b;
	// rev_one_stack_swapping(a);
	// print_stack(a, 'a');
}