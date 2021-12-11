/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 22:02:58 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/06 21:06:08 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_int_stack *stack, int stack_length)
{
	int *temp;

	if (stack_length > 1)
	{
		temp = *stack->num_list;
		*stack->num_list = *(stack->num_list + 1);
		*(stack->num_list + 1) = temp;		
	}
}

int	swap_one(t_int_stack *stack)
{
	int	n;
	
	n = stack_length(stack->num_list);
	swap(stack, n);
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
	if (n > 1)
		return (0);
	return (-1);
}

int	swap_both(t_int_stack *stack_a, t_int_stack *stack_b)
{
	int	n_a;
	int	n_b;
	
	n_a = stack_length(stack_a->num_list);
	n_b = stack_length(stack_b->num_list);
	swap(stack_a, n_a);
	swap(stack_b, n_b);
	ft_putstr_fd("ss\n", 1);
	if ((n_a > 1) && (n_b > 1))
		return (0);
	if ((n_a > 1) && !(n_b > 1))
		return (1);
	if (!(n_a > 1) && (n_b > 1))
		return (2);
	return (-1);
}
