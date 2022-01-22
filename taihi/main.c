/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:06:43 by kkai              #+#    #+#             */
/*   Updated: 2022/01/23 03:03:31 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//#include "/libft.h"


typedef struct s_dlst
{
	bool nil;
	long value;
	struct s_dlst *prev;
	struct s_dlst *next;
}				t_dlst;

void ft_clst_link(t_dlst *now, t_dlst *next)
{
	now->next = next;
	next->prev = now;
}

void ft_clst_insert(t_dlst *lst, t_dlst *new)
{
	ft_clst_link(new, lst->next);
	ft_clst_link(lst, new);
}

void ft_clstadd_front(t_dlst *start, t_dlst *new)
{
	ft_clst_insert(start, new);
}

void ft_clstadd_back(t_dlst *start, t_dlst *new)
{
	ft_clst_insert(start->prev, new);
}

// 番兵ノード作成
t_dlst	*dlstnew()
{
	t_dlst	*new;

	new	= (t_dlst *)malloc(sizeof(t_dlst));
	new->nil = true;
	new->value = 0;
	new->prev = new;
	new->next = new;
	return (new);
}

void	dlstadd_back(t_dlst *a, long num)
{
	t_dlst	*new;

	new = dlstnew();
	new->nil = false;
	new->value = num;
	new->prev = a->prev;
	new->next = a;
	a->prev->

}

int	main(int argc, char **argv)
{
	char	**str;
	t_dlst	*a;
	t_dlst	*b;
	int		i;

	*str = ft_split(argv[1], ' ');
	i = 0;
	a = dlstnew();
	b = dlstnew();
	// aに数字を追加
	dlstadd_back(a, ft_atoi(str[i]));
	return (0);
}
