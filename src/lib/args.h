

#ifndef ARCHSIM_ARGS_H
#define ARCHSIM_ARGS_H

#include "queue.h"

typedef struct argstream_h argstream;
typedef struct settings_h settings;
typedef void arg_handler(argstream *args, settings *opt);

argstream *new_argstream(int argc, char **argv);
char *next_arg(argstream *args)

#endif //ARCHSIM_ARGS_H