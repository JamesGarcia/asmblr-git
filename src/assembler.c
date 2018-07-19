#include <stdio.h>
#include "assembler.h"


int write_header(FILE *dst){

}

int assemble(FILE *src, FILE *dst){
    unsigned int line = 0, col = 0;
    int cx;
    char c;
    while((cx=getc(src))!=EOF){
        c = cx;
        if(c=='\n'){
            line++;
            col = 0;
        }else{
            col++;
        }
    }
}