/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:52:48 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/17 19:39:36 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi_long(const char *nptr)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

int	ft_check_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	i--;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	ft_parse_args(char *arg, t_data *data)
{
	char		**split;
	int			i;
	long int	tmp;

	if (!arg || !*arg)
		return (0);
	split = ft_split(arg, ' ');
	if (!split || !*split)
		return (ft_free_tab((void **)split), 0);
	i = -1;
	while (split[++i])
	{
		if (!ft_check_nbr(split[i]))
			return (ft_free_tab((void **)split), 0);
		tmp = ft_atoi_long(split[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (ft_free_tab((void **)split), 0);
		ft_plstadd_back(&data->stack_a, ft_plstnew((int)tmp));
		data->elem_count++;
	}
	return (ft_free_tab((void **)split), 1);
}

int	ft_get_args(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (!ft_parse_args(argv[i], data))
			return (0);
	data->list_sorted = ft_calloc(data->elem_count + 1, sizeof(int));
	if (!data->list_sorted)
		return (0);
	if (!ft_init_list(data))
		return (0);
	return (1);
}
