#ifndef ARCHSIM_DICT_H
#define ARCHSIM_DICT_H

typedef struct dict_h fixed_dict;

fixed_dict *dict_new(char **keys, elem *vals, unsigned int len);
void dict_free(fixed_dict *D, elem_free_fn *f);
elem dict_lookup(fixed_dict *D, char *key);

#endif //ARCHSIM_DICT_H
