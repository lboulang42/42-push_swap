/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mooves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:53:00 by lboulang          #+#    #+#             */
/*   Updated: 2023/05/23 16:29:32 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_exec_swap(char c, t_data *data)
{
	if (c == 'a')
	{
		if (ft_plstsize(data->stack_a) < 2)
			return (0);
		return (ft_swap(&data->stack_a), 1);
	}
	if (c == 'b')
	{
		if (ft_plstsize(data->stack_b) < 2)
			return (0);
		return (ft_swap(&data->stack_b), 1);
	}
	if (c == 's')
	{
		if (ft_plstsize(data->stack_a) < 2 && ft_plstsize(data->stack_b) < 2)
			return (0);
		return (ft_swap(&data->stack_a), ft_swap(&data->stack_b), 1);
	}
	return (1);
}

int	ft_exec_push(char c, t_data *data)
{
	if (c == 'a')
	{
		if (ft_plstsize(data->stack_b) < 1)
			return (0);
		return (ft_push(&data->stack_b, &data->stack_a), 1);
	}
	if (c == 'b')
	{
		if (ft_plstsize(data->stack_a) < 1)
			return (0);
		return (ft_push(&data->stack_a, &data->stack_b), 1);
	}
	return (0);
}

int	ft_exec_rotate(char c, t_data *data)
{
	if (c == 'a')
	{
		if (ft_plstsize(data->stack_a) < 1)
			return (0);
		return (ft_rotate(&data->stack_a), 1);
	}
	if (c == 'b')
	{
		if (ft_plstsize(data->stack_b) < 1)
			return (0);
		return (ft_rotate(&data->stack_b), 1);
	}
	if (c == 'r')
	{
		if (ft_plstsize(data->stack_a) < 1 && ft_plstsize(data->stack_b) < 1)
			return (0);
		return (ft_rotate(&data->stack_a), ft_rotate(&data->stack_b), 1);
	}
	return (0);
}

int	ft_exec_rrotate(char c, t_data *data)
{
	if (c == 'a')
	{
		if (ft_plstsize(data->stack_a) < 1)
			return (0);
		return (ft_rrotate(&data->stack_a), 1);
	}
	if (c == 'b')
	{
		if (ft_plstsize(data->stack_b) < 1)
			return (0);
		return (ft_rrotate(&data->stack_b), 1);
	}
	if (c == 'r')
	{
		if (ft_plstsize(data->stack_a) < 1 && ft_plstsize(data->stack_b) < 1)
			return (0);
		return (ft_rrotate(&data->stack_a), ft_rrotate(&data->stack_b), 1);
	}
	return (0);
}

int	ft_check_exec(char *str, t_data *data)
{
	int	l;

	l = ft_strlen(str);
	if (!ft_strncmp(str, "sa\n", l) || !ft_strncmp(str, "sb\n", l))
		return (ft_exec_swap(str[1], data));
	if (!ft_strncmp(str, "ss\n", l))
		return (ft_exec_swap(str[1], data));
	if (!ft_strncmp(str, "pa\n", l) || !ft_strncmp(str, "pb\n", l))
		return (ft_exec_push(str[1], data));
	if (!ft_strncmp(str, "ra\n", l) || !ft_strncmp(str, "rb\n", l))
		return (ft_exec_rotate(str[1], data));
	if (!ft_strncmp(str, "rr\n", l))
		return (ft_exec_rotate(str[1], data));
	if (!ft_strncmp(str, "rra\n", l) || !ft_strncmp(str, "rrb\n", l))
		return (ft_exec_rrotate(str[2], data));
	if (!ft_strncmp(str, "rrr\n", l))
		return (ft_exec_rrotate(str[2], data));
	return (0);
}
