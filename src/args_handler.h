#ifndef ARCHSIM_ARGS_HANDLER_H
#define ARCHSIM_ARGS_HANDLER_H

typedef struct{
    char *bc, *tp, *log, *in, *out, *prog;
    int view, nosim, help;
}prog_args;

prog_args *parse_args(int argc, char **argv);

#endif //ARCHSIM_ARGS_HANDLER_H
