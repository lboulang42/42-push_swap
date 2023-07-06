/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:25:51 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/05 01:27:52 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "srcs/ft_printf/ft_printf.h"
# include "srcs/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/*chained list of numbers to sort*/
typedef struct t_stack
{
	int				content;
	int				index;
	int				price;
	int				parent_price;

	struct t_stack	*next;
}					t_stack;

/*data*/
typedef struct s_data
{
	struct t_stack	*stack_a;
	struct t_stack	*stack_b;
	int				elem_count;
	int				*list_sorted;
}					t_data;

/*algo_big.c*/
void	ft_big_init(t_data *data);
void	ft_reorder_list(t_data *data);
void	ft_algo_big(t_data *data);
int		ft_mediane(t_stack **list, int size);
int		ft_find_first(t_stack **stack);

/*algo_little.c*/
void	ft_algo_3(t_stack **stack, char c);
void	ft_put_min_top(t_stack **stack, char c);
void	ft_algo_5(t_stack **stack_1, t_stack **stack_2, char c1, char c2);
int		ft_index_min(t_stack **list);

/*algo_shit.c*/
void	ft_push_swap(t_data *data);
int		ft_check_sorted(t_stack *lst);

/*handle_parent_price.c*/
void	ft_set_price_parent(t_stack **l_src, t_stack **l_dst);
int		ft_find_parent_price(t_stack **stack, int index_before);
int		ft_get_full_price(int price, int parent_price);

/*handle_price.c*/
void	ft_set_price(t_stack **list);
void	ft_rotate_price(int number, t_stack **stack, char c);
void	ft_push_min_price(t_stack **s_src, t_stack **s_dst, char src, char dst);
void	ft_handle_price(t_data *data);

/*mooves.c*/
void	ft_push(t_stack **list1, t_stack **list2, char c);
void	ft_rotate(t_stack **list, char c);
void	ft_rrotate(t_stack **list, char c);
void	ft_swap(t_stack **list, char c);

/*plist.c*/
t_stack	*ft_plstnew(int content);
t_stack	*ft_plstlast(t_stack *lst);
t_stack	*ft_plstprelast(t_stack *lst);
void	ft_plstclear(t_stack **lst);
void	ft_plstadd_back(t_stack **lst, t_stack *new);
int		ft_plstsize(t_stack *lst);

/*init_list.c*/
void	ft_bubble_sort(int *array, int len);
void	ft_set_list(t_data *data);
void	ft_index_list(t_data *data);
int		ft_check_doubles(int *array, int len);
int		ft_init_list(t_data *data);

/*parse.c*/
long	ft_atoi_long(const char *nptr);
int		ft_check_nbr(char *str);
int		ft_parse_args(char *arg, t_data *data);
int		ft_get_args(char **argv, t_data *data);

/*tools.c*/
void	ft_free_tab(void **tab);
void	ft_free_data(t_data *data);

#endif