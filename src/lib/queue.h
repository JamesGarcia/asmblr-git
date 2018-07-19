
#ifndef ARCHSIM_QUEUE_H
#define ARCHSIM_QUEUE_H

#define NULL (void*)0
typedef void* elem;
typedef void elem_free_fn(elem data);

typedef struct single_link_node single_node;
struct single_link_node{
    single_node *next;
    elem data;
};

typedef struct {
    single_node *front, *back;
    unsigned int size;
}queue;

queue *queue_new();
void queue_free(queue *Q, elem_free_fn *f);
void enq(queue *Q, elem data);
elem deq(queue *Q);

#endif //ARCHSIM_QUEUE_H
