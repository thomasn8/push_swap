/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:49:27 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/17 13:52:19 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bitwise_check_silent(t_uint_stack *u_a, t_uint_stack *u_b, int len)
{
	size_t	max;
	int		max_bits;
	int		i;
	int		j;

	max = *u_a->num_list[max_num_index((t_int_stack *)u_a)];
	max_bits = 0;
	while ((max >> max_bits) != 0)
		++max_bits;
	i = -1;
	j = -1;
	while (++i < max_bits)
	{
		while (++j < len)
		{
			if (((*u_a->num_list[0] >> i) & 1) == 1)
				rotate_radix((t_int_stack *)u_a);
			else
				push_radix((t_int_stack *)u_b, (t_int_stack *)u_a);
		}
		j = -1;
		while (u_b->num_list[0] != NULL)
			push_radix((t_int_stack *)u_a, (t_int_stack *)u_b);
	}
}

static void	values_to_indexes(t_uint_stack *u_a, t_uint_stack *u_a_cpy, int len)
{
	int i;
	int j;
	
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (*u_a->num_list[i] == *u_a_cpy->num_list[j])
				*u_a->num_list[i] = j;
		}
	}
}

void	sort_radix_indexes(t_int_stack *a, t_int_stack *b)
{
	unsigned int	*u_num_list;
	int				len;
	t_uint_stack	u_a;
	t_uint_stack	u_a_cpy;
	t_uint_stack	u_b;

	if (is_sorted(a) < 0)
	{
		u_num_list = NULL;
		len = stack_length(a->num_list);
		u_num_list = positiv_num_stack(&u_a, a, u_num_list, len);
		positiv_num_stack(&u_a_cpy, a, u_num_list, len);
		positiv_num_stack(&u_b, b, u_num_list, len);
		bitwise_check_silent(&u_a_cpy, &u_b, len);
		values_to_indexes(&u_a, &u_a_cpy, len);
		bitwise_check(&u_a, &u_b, len);
		free(u_num_list);
		free(u_a.num_list);
		free(u_a_cpy.num_list);
		free(u_b.num_list);
	}
}
