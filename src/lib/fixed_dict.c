
#include <malloc.h>
#include <mem.h>
#include "list.h"
#include "fixed_dict.h"

struct dict_h{
    unsigned int size;
    char **keys;
    elem *vals;
};

fixed_dict *dict_new(char **keys, elem *vals, unsigned int size){
    fixed_dict *D = malloc(sizeof(fixed_dict));
    D->keys = keys;
    D->vals = vals;
    D->size = size;
}
void dict_free(fixed_dict *D, elem_free_fn *f){

}
elem dict_lookup(fixed_dict *D, char *key){
    unsigned int n = D->size;
    while(n-->0 && strcmp(D->keys[n], key));
    return n!=-1?D->vals[n]:NULL;
}

