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
