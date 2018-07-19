#include <stdio.h>

#include "text.h"
#include "args_handler.h"
#include "asmblr.h"

int client_accept(int argc, char **argv){
    prog_args *args = parse_args(argc, argv);
    if(args->help){
        printf(manual_doc);
    }else{
        FILE *prg = fopen(args->prog, "r");
        FILE *src_in = args->in ? fopen(args->in, "r") : stdin;
        FILE *src_out = args->out ? fopen(args->out, "w") : stdout;
        FILE *bc_tmp = args->bc ? fopen(args->bc, "wr") : tmpfile();

        assemble(prg, bc_tmp);
    }
}
