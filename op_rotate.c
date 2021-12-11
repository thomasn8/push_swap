/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:48:24 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 17:05:23 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_one_up(t_int_stack *stack)
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
	int	len;
	int	*temp;

	len = stack_length(stack->num_list);
	if (len > 1)
	{
		temp = stack->num_list[0];
		shift_one_up(stack);
		stack->num_list[len - 1] = temp;
	}
	ft_putchar_fd('r', 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	rotate_both(t_int_stack *a, t_int_stack *b)
{
	int	len_a;
	int	len_b;
	int	*temp_a;
	int	*temp_b;

	len_a = stack_length(a->num_list);
	if (len_a > 1)
	{
		temp_a = a->num_list[0];
		stack_shift_one_up(a);
		a->num_list[len_a - 1] = temp_a;
	}
	len_b = stack_length(b->num_list);
	if (len_b > 1)
	{
		temp_b = b->num_list[0];
		shift_one_up(b);
		b->num_list[len_b - 1] = temp_b;
	}
	ft_putstr_fd("rr\n", 1);
	return (0);
}
