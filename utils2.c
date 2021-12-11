/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:47:07 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 17:17:22 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_num_index(t_int_stack *stack)
{
	int	**list;
	int	i;
	int	min;

	list = stack->num_list;
	i = 0;
	min = 0;
	while (list[i] != NULL)
	{
		if (*list[i] < *list[min])
			min = i;
		i++;
	}
	return (min);
}

int	max_num_index(t_int_stack *stack)
{
	int	**list;
	int	i;
	int	max;

	list = stack->num_list;
	i = 0;
	max = 0;
	while (list[i] != NULL)
	{
		if (*list[i] > *list[max])
			max = i;
		i++;
	}
	return (max);
}

int	direction_to_top(t_int_stack *stack, int i)
{
	int	len;
	int	middle;
	int	direction;

	len = stack_length(stack->num_list);
	middle = len / 2;
	if (i <= middle)
		direction = -1;
	else
		direction = 1;
	return (direction);
}

void	best_rotate(t_int_stack *stack, int i)
{
	int	direction;

	direction = direction_to_top(stack, i);
	if (direction < 0)
	{
		while (i--)
			rotate_one(stack);
	}
	else
	{
		i = stack_length(stack->num_list) - i;
		while (i--)
			rev_rotate_one(stack);
	}
}

int	is_sorted_unrotated(t_int_stack *stack, int min, int max)
{
	int	i;
	int	len;

	i = 0;
	len = stack_length(stack->num_list);
	while (stack->num_list[i] != NULL)
	{
		if (stack->num_list[i + 1] == NULL)
			break ;
		if ((*stack->num_list[i] > *stack->num_list[i + 1])
			&& !((*stack->num_list[i] == max)
				&& (*stack->num_list[i + 1] == min)))
			return (-1);
		i++;
	}
	if ((*stack->num_list[0] < *stack->num_list[len - 1])
		&& !((*stack->num_list[0] == min)
			&& (*stack->num_list[len - 1] == max)))
		return (-1);
	return (0);
}
