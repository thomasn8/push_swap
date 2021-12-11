/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:48:24 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 17:06:16 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_one_down(t_int_stack *stack)
{
	int	i;
	int	len;

	i = 0;
	len = stack_length(stack->num_list);
	while (len-- > 1)
	{
		stack->num_list[len] = stack->num_list[len - 1];
		i++;
	}
}

int	rev_rotate_one(t_int_stack *stack)
{
	int	len;
	int	*temp;

	len = stack_length(stack->num_list);
	if (len > 1)
	{
		temp = stack->num_list[len - 1];
		shift_one_down(stack);
		stack->num_list[0] = temp;
	}
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	rev_rotate_both(t_int_stack *a, t_int_stack *b)
{
	int	len_a;
	int	len_b;
	int	*temp_a;
	int	*temp_b;

	len_a = stack_length(a->num_list);
	if (len_a > 1)
	{
		temp_a = a->num_list[len_a - 1];
		shift_one_down(a);
		a->num_list[0] = temp_a;
	}
	len_b = stack_length(b->num_list);
	if (len_b > 1)
	{
		temp_b = b->num_list[len_b - 1];
		shift_one_down(b);
		b->num_list[0] = temp_b;
	}
	ft_putstr_fd("rrr\n", 1);
	return (0);
}
