/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:48:24 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 16:42:14 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_shift_one_up(t_int_stack *stack)
{
	int	i;

	i = 0;
	while (stack->num_list[i])
	{
		stack->num_list[i] = stack->num_list[i + 1];
		i++;
	}
}

int	rotate_one(t_int_stack *stack)
{
	int	n;
	int	*temp;

	n = stack_length(stack->num_list);
	if (n > 1)
	{
		temp = stack->num_list[0];
		stack_shift_one_up(stack);
		stack->num_list[n - 1] = temp;
	}
	ft_putchar_fd('r', 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	rotate_both(t_int_stack *stack_a, t_int_stack *stack_b)
{
	int	n_a;
	int	n_b;
	int	*temp_a;
	int	*temp_b;

	n_a = stack_length(stack_a->num_list);
	if (n_a > 1)
	{
		temp_a = stack_a->num_list[0];
		stack_shift_one_up(stack_a);
		stack_a->num_list[n_a - 1] = temp_a;
	}
	n_b = stack_length(stack_b->num_list);
	if (n_b > 1)
	{
		temp_b = stack_b->num_list[0];
		stack_shift_one_up(stack_b);
		stack_b->num_list[n_b - 1] = temp_b;
	}
	ft_putstr_fd("rr\n", 1);
	return (0);
}
