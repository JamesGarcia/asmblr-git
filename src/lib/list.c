
#include <malloc.h>
#include "list.h"

struct list_h{
    node *head, *back;
    unsigned int size;
};

list *list_new(){
    list *L = malloc(sizeof(list));
    node *sentinel = malloc(sizeof(node));
    sentinel->next = NULL;
    sentinel->data = NULL;
    L->head = sentinel;
    L->back = sentinel;
    L->size = 0;
    return L;
}
void list_free(list *L, elem_free_fn *f){
    while(L->size){
        elem e = list_head(L);
        if(f)(*f)(e);
    }
    free(L->head);
    free(L);
}
void list_append(list *L, elem data){
    node *tmp = malloc(sizeof(node));
    tmp->next = NULL;
    tmp->data = data;
    L->back->next = tmp;
    L->back = tmp;
    L->size++;
}
void list_prepend(list *L, elem data){
    node *tmp = malloc(sizeof(node));
    tmp->next = L->head->next;
    tmp->data = data;
    L->head->next = tmp;
    if(L->size == 0)
        L->back = tmp;
    L->size++;
}
elem list_head(list *L){
    node *tmp = L->head->next;
    elem e = NULL;
    if(L->size > 0){
        L->head->next = tmp->next;
        e = tmp->data;
        if(--L->size == 0)
            L->back = L->head;
    }
    free(tmp);
    return e;
}
elem list_find(list *L, elem v, elem_cmp_fn *f){
    node *ptr = L->head->next;
    while(ptr){
        if((*f)(v, ptr->data))
            return ptr->data;
        ptr = ptr->next;
    }
    return NULL;
}