/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:55:58 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/05 00:48:14 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//with last only 3 in stack
void	ft_algo_3(t_stack **stack, char c)
{
	t_stack	*tmp;

	tmp = *stack;
	if (ft_check_sorted(*stack))
		return ;
	if (tmp->next->index == ft_plstlast(tmp)->index)
		return ((void)ft_swap(stack, c));
	if (tmp->index < tmp->next->index)
	{
		if (tmp->next->index < ft_plstlast(tmp)->index)
			return ;
		if (tmp->index < ft_plstlast(tmp)->index)
			return ((void)ft_rrotate(stack, c), (void)ft_swap(stack, c));
		return ((void)ft_rrotate(stack, c));
	}
	if (tmp->next->index < ft_plstlast(tmp)->index)
	{
		if (tmp->index < ft_plstlast(tmp)->index)
			return ((void)ft_swap(stack, c));
		return ((void)ft_rotate(stack, c));
	}
	return ((void)ft_swap(stack, c), (void)ft_rrotate(stack, c));
}

int	ft_index_min(t_stack **list)
{
	t_stack	*tmp;
	int		i;
	int		val;
	int		res;

	i = 0;
	val = -1;
	tmp = *list;
	while (tmp)
	{
		if (val == -1 || val > tmp->index)
		{
			val = tmp->index;
			res = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (res);
}

void	ft_put_min_top(t_stack **stack, char c)
{
	if (ft_index_min(stack) < (ft_plstsize(*stack) / 2) + 1)
		while (ft_index_min(stack) != 0)
			ft_rotate(stack, c);
	else
		while (ft_index_min(stack) != 0)
			ft_rrotate(stack, c);
}

/*max 8*/
void	ft_algo_5(t_stack **stack_1, t_stack **stack_2, char c1, char c2)
{
	if (ft_check_sorted(*stack_1))
		return ;
	ft_put_min_top(stack_1, c1);
	ft_push(stack_1, stack_2, c2);
	ft_put_min_top(stack_1, c1);
	if (ft_check_sorted(*stack_1))
		return ((void)ft_push(stack_2, stack_1, c1));
	ft_push(stack_1, stack_2, c2);
	if (!ft_check_sorted(*stack_1))
		ft_algo_3(stack_1, c1);
	ft_push(stack_2, stack_1, c1);
	ft_push(stack_2, stack_1, c1);
}
