
#ifndef ARCHSIM_DEQUE_H
#define ARCHSIM_DEQUE_H

struct deque_node{
    struct deque_node *next, *prev;
    void* value;
};
typedef struct {
    struct deque_node *front, *back;
    unsigned int len;
} deque;

typedef void elem_free(void *x);

deque *deque_new();
void deque_free(deque *D, elem_free *f);
void enq_front(deque *D, void *x);
void enq_back(deque *D, void *x);
void *deq_front(deque *D);
void *deq_back(deque *D);

#endif //ARCHSIM_DEQUE_H