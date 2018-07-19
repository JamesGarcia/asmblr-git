#include <stdint.h>
#include <stdio.h>
#include <malloc.h>

#include "simulator.h"

typedef struct{
    uint32_t mark, size;
    uint8_t* bc;
}program;

#define BYTE uint8_t
#define BYTE_LEN(x) ((BYTE)(8*x))

inline unsigned int fgetuint(FILE *f){
    unsigned int i = 0;
    i |= ((BYTE)fgetc(f)) << BYTE_LEN(4);
    i |= ((BYTE)fgetc(f)) << BYTE_LEN(3);
    i |= ((BYTE)fgetc(f)) << BYTE_LEN(2);
    i |= ((BYTE)fgetc(f)) << BYTE_LEN(1);
    return i;
}

program *read_program(FILE *prog){
    int pad, i;
    program *code = malloc(sizeof(program));
    code->mark = fgetuint(prog);
    code->mark = fgetuint(prog);
    pad = fgetc(prog);
    if(pad==EOF)
        return 1;
    if(pad!=0xAA)
        return 2;
    code->bc = malloc(code->size);
    i = 0;
    while(i<code->size){
        code->bc[i] = (uint8_t) fgetc(prog);
        i++;
    }
    pad = fgetc(prog);
    if(pad==EOF)
        return 1;
    if(pad!=0xAA)
        return 2;
    return code;
}

int simulate_(FILE *prog){
    program *code = read_program(prog);
    BYTE
}