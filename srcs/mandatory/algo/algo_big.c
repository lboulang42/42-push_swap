/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:02:54 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/05 00:44:40 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_mediane(t_stack **list, int size)
{
	int		*tab;
	t_stack	*tmp;
	int		i;

	if (!list)
		return (-1);
	tmp = *list;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (-1);
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->index;
		tmp = tmp->next;
		i++;
	}
	ft_bubble_sort(tab, size);
	i = tab[i / 3];
	return (free(tab), i + 1);
}

void	ft_big_init(t_data *data)
{
	int	med;

	while (ft_plstsize(data->stack_a) > 3)
	{
		if (data->stack_a->index >= data->elem_count - 3)
			ft_rotate(&data->stack_a, 'a');
		med = ft_mediane(&data->stack_a, ft_plstsize(data->stack_a));
		if (data->stack_a->index < med)
			ft_push(&data->stack_a, &data->stack_b, 'b');
		else
			ft_rotate(&data->stack_a, 'a');
	}
}

int	ft_find_first(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (tmp->index == 0)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_reorder_list(t_data *data)
{
	int	i;

	i = 0;
	i = ft_find_first(&data->stack_a);
	if (i < ft_plstsize(data->stack_a) / 2)
		while (data->stack_a->index != 0)
			ft_rotate(&data->stack_a, 'a');
	else
		while (data->stack_a->index != 0)
			ft_rrotate(&data->stack_a, 'a');
}

void	ft_algo_big(t_data *data)
{
	ft_big_init(data);
	if (!ft_check_sorted(data->stack_a))
		ft_algo_3(&data->stack_a, 'a');
	while (data->stack_b)
		ft_handle_price(data);
	ft_reorder_list(data);
}
