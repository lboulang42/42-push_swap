/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:58:55 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/04 23:53:20 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bubble_sort(int *array, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j +1 < len)
			if (array[j + 1] < array[j])
				ft_ptr_swap(&array[j], &array[j +1]);
	}
}

void	ft_set_list(t_data *data)
{
	t_stack	*tmp;
	int		i;

	tmp = data->stack_a;
	i = 0;
	while (tmp)
	{
		data->list_sorted[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
}

int	ft_check_doubles(int *array, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (i + 1 < len && array[i + 1] == array[i])
			return (0);
	return (1);
}

void	ft_index_list(t_data *data)
{
	t_stack	*tmp;
	int		i;

	i = -1;
	while (++i < data->elem_count)
	{
		tmp = data->stack_a;
		while (tmp)
		{
			if (tmp->content == data->list_sorted[i])
				tmp->index = i;
			tmp = tmp->next;
		}
	}
}

int	ft_init_list(t_data *data)
{
	ft_set_list(data);
	ft_bubble_sort(data->list_sorted, data->elem_count);
	if (!ft_check_doubles(data->list_sorted, data->elem_count))
		return (0);
	ft_index_list(data);
	return (1);
}
