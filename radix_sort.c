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

static unsigned int	*positiv_num_stack(t_uint_stack *u_stack, t_int_stack *stack, unsigned int *u_num_list)
{
	int				min;
	int				len;
	int				i;
	unsigned int	*u_num_list_ptr;

	u_num_list_ptr = NULL;
	len = stack_length(stack->num_list);
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

void	sort_radix(t_int_stack *a, t_int_stack *b)
{
	t_uint_stack	u_a;
	t_uint_stack	u_b;
	unsigned int	*u_num_list;

	u_num_list = NULL;
	u_num_list = positiv_num_stack(&u_a, a, u_num_list);
	positiv_num_stack(&u_b, b, u_num_list);
	// print_stack((t_int_stack *)&u_a, 'a');
	// print_stack((t_int_stack *)&u_b, 'b');

	// convertir en base 2 pour faire le tri sur 2 stacks
	
	free(u_num_list);
	free(u_a.num_list);
	free(u_b.num_list);
}
