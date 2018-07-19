#ifndef ARCHSIM_LIST_H
#define ARCHSIM_LIST_H

#define NULL (void*)0
typedef void* elem;
typedef void elem_free_fn(elem data);
typedef int elem_cmp_fn(elem a, elem b);

typedef struct list_node node;
struct list_node{
    node *next;
    elem data;
};

typedef struct list_h list;

list *list_new();
void list_free(list *L, elem_free_fn *f);
void list_append(list *L, elem data);
void list_prepend(list *L, elem data);
elem list_head(list *L);
elem list_find(list *L, elem v, elem_cmp_fn *f);
unsigned int list_size(list *L);

#endif //ARCHSIM_LIST_H
