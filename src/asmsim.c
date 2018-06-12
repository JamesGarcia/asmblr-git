//
// Created by garci on 6/8/2018.
//

#include "asmsim.h"
//asm sim

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct{
    uint32_t init;
    int8_t dir;
}HEADER;
typedef struct{
    HEADER *head;
    uint8_t *code;
    size_t len;
}PROGRAM;

int simulate(FILE *fp, PROGRAM *prog, const uint8_t offs){
    size_t ptr = offs;
    uint8_t mode = 0, dir = 1, ins, *mem = malloc(16 * sizeof(uint8_t));
    mem[3] = 1;
    while(0 <= ptr && ptr < prog-> len && (ins = prog->code[ptr]) != 0){
        uint8_t a = (ins >> 4)&15, b = ins&15;
        if(b != 0 && b!= 1 && b != 15){
            mem[b] = mode ? a : mem[a];
        }
        if(ins == 0xA0){/*IMM*/
            mode = 0;
        }
        if(ins == 0xAF){/*IND*/
            mode = 1;
        }
        if(ins == 0x21){/*REV*/
            dir ^= 1;
        }
        ptr = ptr + mem[3] * dir ? 1 : -1;
    }
    return 0;
}
void unpackHeader(FILE *fp, PROGRAM *prog, uint8_t *offs){
    fseek(fp, 0, SEEK_SET);
    int32_t hval = 0, mask = 0x7FFFFFFF;
    prog->head = malloc(sizeof(HEADER));
    fread(&hval, 4, 1, fp);
    prog->head->init = hval & mask;
    prog->head->dir = hval &~ mask ? -1 : 1;
    *offs = 4;
}
void unpackCode(FILE *fp, PROGRAM *prog, const uint8_t offs){
    fseek(fp, offs, SEEK_SET);
    size_t len = 0, mark = 0;
    int val;
    while((val=fgetc(fp)) != EOF){
        if(len <= mark){
            len = len * 2 + 1;
            uint8_t *tmp = malloc(len * sizeof(uint8_t));
            for(size_t i = 0; i < len/2; i++){
                tmp[i] = prog->code[i];
            }
            free(prog->code);
            prog->code = tmp;
        }
        prog->code[mark++] = (uint8_t) val;
    }
    if(mark < len){
        free(&prog->code[mark]);
    }
    prog->len = mark;
}
int launch_asmsim(const char *fname){
    FILE *fp = fopen(fname, "rb");
    PROGRAM *prog = malloc(sizeof(PROGRAM));
    uint8_t offs = -1;
    unpackHeader(fp, prog, &offs);
    unpackCode(fp, prog, offs);
    fclose(fp);
    if(offs == -1)
        return 1;
    return simulate(fp, prog, offs);
}

