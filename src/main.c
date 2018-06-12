/** assembler for project computer asm
 *  @authors: jsg
 *  @version: 0.0.0
 */


#include <assert.h>
#include <mem.h>
#include <getopt.h>
#include <stdio.h>
#include <ctype.h>

#include "asmblr.h"
#include "asmsim.h"

/*
int main(int argc, char *argv[]){
    FILE *src, *dst;
    if(argc != 5 ){
        fprintf(stderr, "usage: asmlbr -i <> -o <> ");
        return 1;
    }else if(!strcmp(argv[1], "-i") && !strcmp(argv[3], "-o")){
        src = fopen(argv[2], "r");
        dst = fopen(argv[4], "w+");
    }else if(!strcmp(argv[1], "-o") && !strcmp(argv[3], "-i")){
        src = fopen(argv[4], "r");
        dst = fopen(argv[2], "w+");
    }else{
        fprintf(stderr, "usage: asmlbr -i <> -o <> ");
        return 1;
    }
    //parse(src, dst);
    fclose(src);
    fclose(dst);
    return 0;
}
*/

#define STREQ(a, b) (!strcmp((a), (b)))
#define STRNEQ(a, b) (strcmp((a), (b)))

int main(int argc, char **argv){
    assert(argc > 2);
    int c;
    const char *i_val = NULL, *o_val = NULL;
    while((c=getopt(argc, argv, "i:o:")) != -1){
        switch (c) {
            case 'i':
                i_val = optarg;
                break;
            case 'o':
                o_val = optarg;
                break;
            case '?':
                if(optopt == 'i' || optopt == 'o'){
                    fprintf(stderr,
                            "Option -%c requires an argument\n",
                            optopt);
                } else if(isprint(optopt)) {
                    fprintf(stderr,
                            "Unknown option '-%c'",
                            optopt);
                } else{
                    fprintf(stderr,
                            "Unknown option character '\\x%x\n'",
                            optopt);
                }
                return 1;
            default:
                return 1;
        }
    }
    return
        STREQ(argv[1], "asmblr") ? launch_asmblr(i_val, o_val) :
        STREQ(argv[1], "asmsim") ? launch_asmsim(i_val) :
        1;
}