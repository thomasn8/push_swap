/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:48:24 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/17 12:51:35 by tnanchen         ###   ########.fr       */
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

static void	stack_shift_one_down(t_int_stack *stack)
{
	int	i;
	int	len;

	i = 0;
	len = stack_length(stack->num_list);
	while (len--)
	{
		stack->num_list[len + 1] = stack->num_list[len];
		i++;
	}
}

int	push(t_int_stack *dst, t_int_stack *src)
{
	int	src_exists;
	int	*temp;

	src_exists = 0;
	if (*src->num_list)
	{
		temp = *src->num_list;
		stack_shift_one_up(src);
		stack_shift_one_down(dst);
		*dst->num_list = temp;
		src_exists = 1;
	}
	ft_putchar_fd('p', 1);
	ft_putchar_fd(dst->name, 1);
	ft_putchar_fd('\n', 1);
	if (src_exists)
		return (0);
	return (-1);
}

int	push_radix(t_int_stack *dst, t_int_stack *src)
{
	int	src_exists;
	int	*temp;

	src_exists = 0;
	if (*src->num_list)
	{
		temp = *src->num_list;
		stack_shift_one_up(src);
		stack_shift_one_down(dst);
		*dst->num_list = temp;
		src_exists = 1;
	}
	if (src_exists)
		return (0);
	return (-1);
}
