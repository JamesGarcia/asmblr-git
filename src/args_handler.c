#include <getopt.h>
#include <stdio.h>
#include <mem.h>
#include <malloc.h>

#include "error.h"
#include "text.h"

#include "args_handler.h"

void handle_optargs(prog_args *args, int argc, char **argv){
    int c;
    while((c=getopt(argc, argv, "bB:tT:lL:i:o:xvh"))!=-1){
        switch(c){
            case 'b':
                optarg = "out.bc";
            case 'B':
                raise_error(args->bc, BRESET);
                args->bc = optarg;
                break;
            case 't':
                optarg = "out.tp";
            case 'T':
                raise_error(args->tp, TRESET);
                args->tp = optarg;
                break;
            case 'l':
                optarg = "sim.log";
            case 'L':
                raise_error(args->log, LRESET);
                args->log = optarg;
                break;
            case 'i':
                args->in = optarg;
                break;
            case 'o':
                args->out = optarg;
                break;
            case 'v':
                args->view = 1;
                break;
            case 'x':
                args->nosim = 1;
                break;
            case 'h':
                args->help = 1;
                break;
            case '?':
                add_error(strchr("BTLio", optopt) ? NOARG : BADOPT);
                break;
            default:
                add_error(MAXERR);
                break;
        }
    }
}

void handle_nonoptargs(prog_args *args, int argc, char **argv){
    int n = optind;
    while(n<argc){
        raise_error(args->prog, PRESET);
        args->prog = argv[n];
    }
    raise_error(!args->prog, PUNSET);
}

void handle_badargs(prog_args *args){
    int sim = args->view || args->bc || args->tp || args->log;
    int nosim = args->nosim || args->help;
    raise_error(sim && nosim, BADSYN);
    raise_error(args->help && args->prog, BADSYN);
}

prog_args *parse_args(int argc, char **argv){
    prog_args *args = calloc(1, sizeof(prog_args));
    clear_error();
    handle_optargs(args, argc, argv);
    handle_nonoptargs(args, argc, argv);
    test_error();
    handle_badargs(args);
    test_error();
    return args;
}
