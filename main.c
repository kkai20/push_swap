/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:06:43 by kkai              #+#    #+#             */
/*   Updated: 2022/01/07 18:03:25 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//#include "/libft.h"


typedef struct s_dlst
{
	long value;
	bool nil;
	struct s_dlst *next;
	struct s_dlst *prev;
}				t_dlst;


/*char	sa(t_dlst *num, t_dlst *num2)
{
	long	tmp;
	long	dig1;
	long	dig2;

	tmp = 0;
	dig1 = num->next;
	dig2 = num2->next;
	tmp = dig1;
	num = dig2;
	num2 = tmp;
	return ("sa");
}*/

t_dlst *sentinelnode(bool value)
{
	t_dlst *new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (new == NULL)
		exit(1);
	new->nil = value;
	new->next = NULL;
	return (new);
}

t_dlst	*ft_lstnew(long	value)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (new == NULL)
		exit (1);
	new -> value = value;
	new -> next = NULL;
	return (new);
}

void dlst_addfront(t_dlst *lst, t_dlst *new)
{
	if (lst == NULL || new == NULL)
		exit (1);
	lst->next = new;
}

void dlst_addback(t_dlst *lst, t_dlst *new)
{
	if (lst == NULL || new == NULL)
		exit(1);
	lst->prev = new;
	new->next = lst;
}

int	main()
{
	t_dlst *node;
	t_dlst *node2;
	t_dlst *node3;

	node = sentinelnode(1);
	node2 = ft_lstnew(10);
	dlst_addfront(node, node2);
	node3 = ft_lstnew(20);
	dlst_addback(node, node3);
	printf("%ld, %ld\n", node2->value, node3->value);
	//sa(node2, node3);
	return (0);
}
