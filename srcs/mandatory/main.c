/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:27:06 by lboulang          #+#    #+#             */
/*   Updated: 2023/05/23 16:32:06 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sorted(t_stack *lst)
{
	t_stack	*tmp;
	int		i;

	tmp = lst;
	i = tmp->index;
	while (tmp)
	{
		if (i > tmp->index)
			return (0);
		i = tmp->index;
		tmp = tmp->next;
	}
	return (1);
}

/*separate algo for 3, 5 and above*/
void	ft_push_swap(t_data *data)
{
	if (data->elem_count <= 3)
		return ((void)ft_algo_3(&data->stack_a, 'a'));
	if (data->elem_count <= 5)
		return ((void)ft_algo_5(&data->stack_a, &data->stack_b, 'a', 'b'));
	return ((void)ft_algo_big(data));
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
	if (!ft_get_args(argv, data))
		return (ft_free_data(data), ft_printf("Error\n"), 0);
	if (ft_check_sorted(data->stack_a))
		return (ft_free_data(data), 0);
	ft_push_swap(data);
	return (ft_free_data(data), 0);
}
