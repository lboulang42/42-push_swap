/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:06:23 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/21 17:07:56 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_swap(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*list || !list[0]->next)
		return ;
	tmp = *list;
	tmp2 = list[0]->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	*list = tmp2;
}

void	ft_push(t_stack **list1, t_stack **list2)
{
	t_stack	*tmp;

	if (!*list1)
		return ;
	tmp = *list1;
	*list1 = list1[0]->next;
	tmp->next = *list2;
	*list2 = tmp;
}

void	ft_rotate(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*list)
		return ;
	tmp = *list;
	tmp2 = ft_plstlast(*list);
	*list = list[0]->next;
	tmp->next = NULL;
	tmp2->next = tmp;
}

t_stack	*ft_plstprelast(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_rrotate(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*list || !list[0]->next)
		return ;
	tmp = ft_plstprelast(*list);
	tmp2 = ft_plstlast(*list);
	tmp->next = NULL;
	tmp2->next = *list;
	*list = tmp2;
}
