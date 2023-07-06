/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parent_price.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:15:32 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/05 00:48:07 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_set_price_parent(t_stack **l_src, t_stack **l_dst)
{
	t_stack	*tmp_src;

	tmp_src = *l_src;
	while (tmp_src)
	{
		tmp_src->parent_price = ft_find_parent_price(l_dst, tmp_src->index);
		tmp_src = tmp_src->next;
	}
}

int	ft_find_parent_price(t_stack **stack, int index_before)
{
	t_stack	*tmp;
	int		parent_index;
	int		parent_price;

	tmp = *stack;
	parent_index = 99999;
	parent_price = 99999;
	while (tmp)
	{
		if (tmp->index > index_before && tmp->index < parent_index)
		{
			parent_index = tmp->index;
			parent_price = tmp->price;
		}
		tmp = tmp->next;
	}
	return (parent_price);
}

int	ft_get_full_price(int price, int parent_price)
{
	if (price < 0)
		price = price * -1;
	if (parent_price < 0)
		parent_price = parent_price * -1;
	return (price + parent_price);
}
