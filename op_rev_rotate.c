/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:48:24 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/06 20:44:58 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// décale tous les num (sauf le dernier) d'un rang vers la fin de la pile
static void	stack_shift_one_down(t_int_stack *stack)
{
	int	i;
	int	n;

	i = 0;
	n = stack_length(stack->num_list);
	while (n-- > 1)
	{
		stack->num_list[n] = stack->num_list[n - 1];
		i++;
	}
}

int	rev_rotate_one(t_int_stack *stack)
{
	int	n;
	int *temp;
	
	n = stack_length(stack->num_list);
	if (n > 1)
	{
		temp = stack->num_list[n - 1];
		stack_shift_one_down(stack);
		stack->num_list[0] = temp;
	}
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}


int	rev_rotate_both(t_int_stack *stack_a, t_int_stack *stack_b)
{
	int	n_a;
	int	n_b;
	int *temp_a;
	int *temp_b;

	n_a = stack_length(stack_a->num_list);
	if (n_a > 1)
	{
		temp_a = stack_a->num_list[n_a - 1];
		stack_shift_one_down(stack_a);
		stack_a->num_list[0] = temp_a;
	}
	n_b = stack_length(stack_b->num_list);
	if (n_b > 1)
	{
		temp_b = stack_b->num_list[n_b - 1];
		stack_shift_one_down(stack_b);
		stack_b->num_list[0] = temp_b;
	}
	ft_putstr_fd("rrr\n", 1);
	return (0);
}
