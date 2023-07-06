/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 01:20:08 by lboulang          #+#    #+#             */
/*   Updated: 2023/05/04 14:39:28 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_sorted(t_data *data)
{
	t_stack	*tmp;
	int		before;
	int		i;

	i = 0;
	tmp = data->stack_a;
	if (ft_plstsize(data->stack_b))
		return (0);
	while (tmp)
	{
		if (i == 0)
			before = tmp->content;
		if (before > tmp->content)
			return (0);
		before = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	static char	*buffer;
	char		*str;

	if (argc == 1)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
	if (!ft_get_args(argv, data))
		return (ft_free_data(data), ft_printf("Error\n"), 0);
	while (1)
	{
		str = boosted_gnl(buffer, 0);
		if (!str)
			break ;
		if (!ft_check_exec(str, data))
			return (free(str), ft_free_data(data), ft_printf("Error\n"), 0);
		free(str);
	}
	if (!ft_check_sorted(data))
		return (ft_free_data(data), ft_printf("KO\n"), 0);
	return (ft_free_data(data), ft_printf("OK\n"), 0);
}
