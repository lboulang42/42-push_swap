/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <lboulang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:25:51 by lboulang          #+#    #+#             */
/*   Updated: 2023/04/21 17:18:51 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "srcs/ft_printf/ft_printf.h"
# include "srcs/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
/*chained list of numbers to sort*/
typedef struct t_stack
{
	int				content;
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

/*
exec_moove
*/
int		ft_exec_swap(char c, t_data *data);
int		ft_exec_push(char c, t_data *data);
int		ft_exec_rotate(char c, t_data *data);
int		ft_exec_rrotate(char c, t_data *data);
int		ft_check_exec(char *str, t_data *data);

/*
mooves
*/
void	ft_swap(t_stack **list);
void	ft_push(t_stack **list1, t_stack **list2);
void	ft_rotate(t_stack **list);
t_stack	*ft_plstprelast(t_stack *lst);//?
void	ft_rrotate(t_stack **list);

/*
init_list
*/
void	ft_bubble_sort(int *array, int len);
void	ft_set_list(t_data *data);
int		ft_check_doubles(int *array, int len);
int		ft_init_list(t_data *data);

/*
parse_bonus
*/
long	ft_atoi_long(const char *nptr);
int		ft_check_nbr(char *str);
int		ft_parse_args(char *arg, t_data *data);
int		ft_get_args(char **argv, t_data *data);

/*
main
*/
int		main(int argc, char **argv);

/*
plist_bonus
*/
t_stack	*ft_plstnew(int content);
t_stack	*ft_plstlast(t_stack *lst);
void	ft_plstclear(t_stack **lst);
void	ft_plstadd_back(t_stack **lst, t_stack *new);
int		ft_plstsize(t_stack *lst);

/*
tools
*/
void	ft_free_tab(void **tab);
void	ft_free_data(t_data *data);

/*
boosted_gnl
*/
char	*ft_get_file(char *buffer, int fd);
char	*ft_get_line(char *buffer);
char	*boosted_gnl(char *buffer, int fd);
char	*ft_join_free(char *str1, char *str2);
#endif