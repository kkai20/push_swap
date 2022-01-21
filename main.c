#include "./libft/libft.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct s_dlist t_dlist;
struct s_dlist {
    t_dlist *next;
    t_dlist *prev;
    bool    nil;
    long    num;
};

// 空のリストを作成（番兵ノードを作成）
t_dlist *dlstnew() {
	t_dlist	*new = (t_dlist *)malloc(sizeof(t_dlist));
	new->nil = true;
	new->num = 0;
	new->prev = new;
	new->next = new;
    return new;
}

// 1     a 2 4
// 1 new a 2 4
void 	dlistadd_back(t_dlist *a, long num) {
	t_dlist *new = dlstnew();
    new->nil = false;
    new->num = num;
	new->prev = a->prev;
    new->next = a;
    a->prev->next = new;
    a->prev = new;
}

void print_dlist(t_dlist *a, t_dlist *b) {
    printf("a: ");
    a = a->next;
    while (!a->nil) {
        printf("%ld ", a->num);
        a = a->next;
    }
    printf("\n");

    printf("b: ");
    b = b->next;
    while (!b->nil) {
        printf("%ld ", b->num);
        b = b->next;
    }
    printf("\n");
}

void ft_swap(long *a, long *b) {
    long tmp = *a;
    *a = *b;
    *b = tmp;
}

long dlistsize(t_dlist *a) {
    long size = 0;
    a = a->next;
    while (!a->nil) {
        size++;
        a = a->next;
    }
    return size;
}

// a: nil 1 3
// a: nul 3 1
void sa(t_dlist *a, t_dlist *b) {
    if (dlistsize(a) < 2)
        return ;
    t_dlist *cur = a->next;
    t_dlist *next = a->next->next;
    ft_swap(&(cur->num), &(next->num));
}

// b: nil 1 3
// b: nul 3 1
void sb(t_dlist *a, t_dlist *b) {
    if (dlistsize(b) < 2)
        return ;
    t_dlist *cur = b->next;
    t_dlist *next = b->next->next;
    ft_swap(&(cur->num), &(next->num));
}

// a: nil 1 2 3 4
// a: nil 2 3 4 1
void ra(t_dlist *a, t_dlist *b) {
	// 1. a->next の数字をaのケツに追加する(dlistadd_back)
	dlistadd_back(a, a->next->num);
    // 2. a->next を削除する(dlistdel_front)
}

void rra(t_dlist *a, t_dlist *b) {
	// 1. a->prev の数字をaの頭に追加する(dlistadd_front)
    // 2. a->prev を削除する(dlistdel_back)
}

int main(int argc, char **argv) {
    // 第一引数の文字列をスペース区切りで分割
    char **strs = ft_split(argv[1], ' ');

    // 空リストを作成
    t_dlist *a = dlstnew();
    t_dlist *b = dlstnew();

    // aに数字を追加
    for (int i = 0; strs[i]; i++) {
        dlistadd_back(a, ft_atoi(strs[i]));
    }

    // bに適当に追加
    dlistadd_back(b, 1);
    // dlistadd_back(b, 3);

    // a, bのデータを全て表示
    print_dlist(a, b);

    sa(a, b);
    sb(a, b);
    // ss(a, b);
    ra(a, b);

    print_dlist(a, b);
}
