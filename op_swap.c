/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 22:02:58 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 17:07:47 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_int_stack *stack, int stack_length)
{
	int	*temp;

	if (stack_length > 1)
	{
		temp = *stack->num_list;
		*stack->num_list = *(stack->num_list + 1);
		*(stack->num_list + 1) = temp;
	}
}

int	swap_one(t_int_stack *stack)
{
	int	len;

	len = stack_length(stack->num_list);
	swap(stack, len);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
	if (len > 1)
		return (0);
	return (-1);
}

int	swap_both(t_int_stack *a, t_int_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_length(a->num_list);
	len_b = stack_length(b->num_list);
	swap(a, len_a);
	swap(b, len_b);
	ft_putstr_fd("ss\n", 1);
	if ((len_a > 1) && (len_b > 1))
		return (0);
	if ((len_a > 1) && !(len_b > 1))
		return (1);
	if (!(len_a > 1) && (len_b > 1))
		return (2);
	return (-1);
}
