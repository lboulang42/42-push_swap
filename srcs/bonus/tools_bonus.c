/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:55:43 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/21 17:16:33 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_tab(void **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_free_data(t_data *data)
{
	ft_plstclear(&data->stack_a);
	ft_plstclear(&data->stack_b);
	if (data->list_sorted)
		free(data->list_sorted);
	free(data);
}
