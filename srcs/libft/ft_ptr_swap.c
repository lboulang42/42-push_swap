/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:53:29 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/05 00:47:45 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ptr_swap(int *ptr_src, int *ptr_dst)
{
	int	tmp;

	tmp = *ptr_src;
	*ptr_src = *ptr_dst;
	*ptr_dst = tmp;
}
