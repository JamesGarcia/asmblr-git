
#include "args.h"

typedef struct {

}OPTION;

void handle_long_opt(){

}

void handle_short_opt(){

}

void handle_word_opt(){

}

void parse_args(int argc, char **argv){
    int n = 0;
    while(n<argc){
        char *arg = argv[n];
        if(*arg == '-'){
            if(arg[1] == '-'){
                handle_long_opt();
            }else{
                handle_short_opt();
            }
        }else{
            handle_word_opt();
        }
    }
}