
#include <malloc.h>
#include "args.h"
#include "fixed_dict.h"

struct argstream_h{
    int argc,n;
    char **argv;
};
argstream *new_argstream(int argc, char **argv){
    argstream *args = malloc(sizeof(argstream));
    args->argv = argv;
    args->argc = argc;
    args->n = 0;
}
char *next_arg(argstream *args){
    return args->n >= args->argc ? 0 : args->argv[args->n++];
}

char *argparse(argstream *args, fixed_dict *dict){
    char *c;
    while((c=next_arg(args))){
        arg_handler *f = dict_lookup(dict, c);
        if(f)(*f)(c, args, NULL);
        else {fprintf(stderr, c); return 1;}
    }
}