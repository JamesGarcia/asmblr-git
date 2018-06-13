
#include <malloc.h>
#include "queue.h"

queue *queue_new(){
    queue *Q = malloc(sizeof(queue));
    single_node *dummy = malloc(sizeof(single_node));
    dummy->next = NULL;
    Q->front = dummy;
    Q->back = dummy;
    Q->size = 0;
    return Q;
}
void queue_free(queue *Q, elem_free_fn *f){
    while(Q->size){
        elem data = deq(Q);
        if(f)(*f)(data);
    }
    free(Q->front);
    free(Q);
}
void enq(queue *Q, elem data){
    single_node *tmp = malloc(sizeof(single_node));
    tmp->next = NULL;
    tmp->data = data;
    Q->back->next = tmp;
    Q->size++;
}
elem deq(queue *Q){
    single_node *tmp = Q->front->next;
    elem data = NULL;
    if(tmp){
        Q->front->next = tmp->next;
        data = tmp->data;
    }
    free(tmp);
    Q->size--;
    return data;
}