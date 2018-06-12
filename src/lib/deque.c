
#include <malloc.h>
#include "deque.h"

deque *deque_new(){
    deque *D = malloc(sizeof(deque));
    D->back = (void*)0;
    D->front = (void*)0;
    D->len = 0;
    return D;
}
void deque_free(deque *D, elem_free *f){
    while(D->len){

    }
    free(D->front);
    free(D->back);
    free(D);
}
void enq_front(deque *D, void *x){

}
void enq_back(deque *D, void *x){

}
void *deq_front(deque *D){

}
void *deq_back(deque *D){

}