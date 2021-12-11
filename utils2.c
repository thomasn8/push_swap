/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:47:07 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 01:52:54 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get index of min num in list
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

// get index of max num in list
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

// give the closest direction from num[i] to the top of the stack : (-1 = left) | (1 = right)
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

// rotate the stack in the closest direction to bring num[i] at the top of the stack
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

// check si la stack est triée mais permet qu'elle ne soit pas dans la bonne rotation
// c-a-d qu'il y ait 1 occurence de num pas dans l'ordre, si ces num sont max suivi de min
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
	// liste pas triée si a[0] < a[end]
	// car par dans la bonne rotation et a[0] sera après a[end] dans la bonne rotation
	// (sauf si a[0] et a[end] sont effectivement les min et max de la list)
	if ((*stack_a->num_list[0] < *stack_a->num_list[len-1])
		&& !((*stack_a->num_list[0] == min) && (*stack_a->num_list[len-1] == max)))
		return (-1);
	return (0);
}
