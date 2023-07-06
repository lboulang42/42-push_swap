/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_price.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:11:51 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/05 00:53:35 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_price(t_stack **list)
{
	t_stack	*tmp;
	int		i;
	int		mid;

	mid = ft_plstsize(*list) / 2;
	i = 0;
	tmp = *list;
	while (tmp && i <= mid)
	{
		tmp->price = i;
		tmp = tmp->next;
		i++;
	}
	if (ft_plstsize(*list) % 2 == 0)
		i--;
	i--;
	while (tmp)
	{
		tmp->price = i * -1;
		tmp = tmp->next;
		i--;
	}
}

void	ft_rotate_price(int number, t_stack **stack, char c)
{
	if (number < 0)
		while (number++ < 0)
			ft_rrotate(stack, c);
	else
		while (number-- > 0)
			ft_rotate(stack, c);
}

void	ft_push_min_price(t_stack **s_src, t_stack **s_dst, char src, char dst)
{
	t_stack	*tmp;
	t_stack	*mini;
	int		full_price;

	tmp = *s_src;
	mini = tmp;
	while (tmp)
	{
		full_price = ft_get_full_price(tmp->price, tmp->parent_price);
		if (full_price < ft_get_full_price(mini->price, mini->parent_price))
			mini = tmp;
		tmp = tmp->next;
	}
	ft_rotate_price(mini->price, s_src, src);
	ft_rotate_price(mini->parent_price, s_dst, dst);
	ft_push(s_src, s_dst, dst);
}

void	ft_handle_price(t_data *data)
{
	ft_set_price(&data->stack_a);
	ft_set_price(&data->stack_b);
	ft_set_price_parent(&data->stack_b, &data->stack_a);
	ft_push_min_price(&data->stack_b, &data->stack_a, 'b', 'a');
}
