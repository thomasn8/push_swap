/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:47:07 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 13:02:33 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_num_index(t_int_stack *stack)
{
	int **list;
	int	i;
	int min;
	
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
	int **list;
	int	i;
	int max;
	
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
	int	length;
	int middle;
	int direction;

	length = stack_length(stack->num_list);
	middle = length / 2;
	if (i <= middle)
		direction = -1;
	else
		direction = 1;
	return (direction);
}

void	best_rotate(t_int_stack *stack, int i)
{
	int direction;

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

int	is_sorted_unrotated(t_int_stack *stack_a, int min, int max)
{
	int i;
	int len;

	i = 0;
	len = stack_length(stack_a->num_list);
	while (stack_a->num_list[i] != NULL)
	{
		if (stack_a->num_list[i + 1] == NULL)
			break;
		if ((*stack_a->num_list[i] > *stack_a->num_list[i + 1]) 
			&& !((*stack_a->num_list[i] == max) && (*stack_a->num_list[i + 1] == min)))
			return (-1);
		i++;
	}
	if ((*stack_a->num_list[0] < *stack_a->num_list[len-1])
		&& !((*stack_a->num_list[0] == min) && (*stack_a->num_list[len-1] == max)))
		return (-1);
	return (0);
}
