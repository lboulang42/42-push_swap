/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:30:51 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/05 01:27:59 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Create New List*/
t_stack	*ft_plstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}

/*
Return Last List Of Chained-List
*/
t_stack	*ft_plstlast(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
Clear Every List Of Chained List
*/
void	ft_plstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
	}
}

/*Add list at end of list*/
void	ft_plstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lstlast;

	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		lstlast = ft_plstlast(*lst);
		lstlast->next = new;
	}
}

/*return lst nber of elem*/
int	ft_plstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
