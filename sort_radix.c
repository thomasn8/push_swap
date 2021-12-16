#include "push_swap.h"

static unsigned int	*unsigned_list(t_int_stack *stack, int len, int min)
{
	int	i;
	unsigned int *u_num_list;

	u_num_list = malloc(len * sizeof(unsigned int));
	if (!u_num_list)
		error(MALLOC_ERR);
	i = -1;
	if (min < 0)
		min *= -1;
	else
		min = 0;
	while (stack->num_list[++i])
		u_num_list[i] = *stack->num_list[i] + min;
	return (u_num_list);
}

static unsigned int	*positiv_num_stack(t_uint_stack *u_stack, t_int_stack *stack, unsigned int *u_num_list, int len)
{
	int				min;
	int				i;
	unsigned int	*u_num_list_ptr;

	u_num_list_ptr = NULL;
	u_stack->num_list = malloc((len + 1) * sizeof(unsigned int **));
	if (!stack->num_list)
		error(MALLOC_ERR);
	i = 0;
	if (stack->name == 'a')
	{
		min = *stack->num_list[min_num_index(stack)];
		u_num_list = unsigned_list(stack, len, min);
		u_num_list_ptr = u_num_list;
		while (len--)
			u_stack->num_list[i++] = u_num_list++;
	}
	else
	{
		while (len--)
			u_stack->num_list[i++] = NULL;
	}
	u_stack->num_list[i] = NULL;
	u_stack->name = stack->name;
	return (u_num_list_ptr);
}

static void	bitwise_check(t_uint_stack *u_a, t_uint_stack *u_b, int len)
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
			if (((*u_a->num_list[0] >> i)&1) == 1)
				rotate_one((t_int_stack *)u_a);
			else
				push((t_int_stack *)u_b, (t_int_stack *)u_a);
		}
		j = -1;
		while (u_b->num_list[0] != NULL)
			push((t_int_stack *)u_a, (t_int_stack *)u_b);
	}
}

void	sort_radix(t_int_stack *a, t_int_stack *b)
{
	unsigned int	*u_num_list;
	int				len;
	t_uint_stack	u_a;
	t_uint_stack	u_b;

	u_num_list = NULL;
	len = stack_length(a->num_list);
	u_num_list = positiv_num_stack(&u_a, a, u_num_list, len);
	positiv_num_stack(&u_b, b, u_num_list, len);
	bitwise_check(&u_a, &u_b, len);
	free(u_num_list);
	free(u_a.num_list);
	free(u_b.num_list);
}
