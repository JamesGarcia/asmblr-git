//
// Created by garci on 6/4/2018.
//

#include "asmblr.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>



#define COMMENT_START ';'
#define COMMENT_END   '\n'

/*
 * ASSEMBLER SYNTAX
 *
 * MOV x y  => x,y are single digit hexadecimal numbers referring to registers
 * IMM      := MOV A 0
 * IND      := MOV A F
 * NOP      := MOV 1 1
 * REV      := MOV 2 1
 * HLT      := MOV 0 0
 *
 */


#define MOV 0xFF
#define IMM 0xA0
#define IND 0xAF
#define NOP 0X11
#define REV 0X21
#define HLT 0X00
#define OPCODE uint8_t
typedef struct {
    OPCODE payload;
}TOKEN;

TOKEN *newToken(char *str){
    TOKEN *tok = malloc(sizeof(TOKEN));
    if(0==strcmp("MOV", str)) {
        tok->payload = MOV;
    }else if(0==strcmp("IMM", str)) {
        tok->payload = IMM;
    }else if(0==strcmp("IND", str)) {
        tok->payload = IND;
    }else if(0==strcmp("NOP", str)) {
        tok->payload = NOP;
    }else if(0==strcmp("REV", str)) {
        tok->payload = REV;
    }else if(0==strcmp("HLT", str)) {
        tok->payload = HLT;
    }else{
        char **str_end = malloc(sizeof(char*));
        tok->payload = (OPCODE) strtol(str, str_end, 16);
        assert(errno != ERANGE && 0 != strcmp(str, *str_end));
        free(str_end);
    }
    free(str);
    return tok;
}

/**
 *
 * @param src   file for reading a whitespace delimited token
 * @attention   ignores text within comment boundaries
 * @return      pointer to a token
 */
TOKEN *getToken(FILE *src){
    int i, ptr = 0;
    char c, *buf = malloc(16 * sizeof(char));
    while((i=fgetc(src))!=EOF){
        c = (char)toupper(i);
        if(isspace(c)){
            //ignore
            continue;
        } else if(c==COMMENT_START){
            //ignore and seek newline
            while((i=fgetc(src))!=EOF)
                if((char)i==COMMENT_END) {
                    break;
                }
        } else{
            //tokenize
            *buf = c;
            while((i=fgetc(src))!=EOF){
                c = (char)toupper(i);
                if(isspace(c)){
                    //token is finished
                    buf[++ptr]=0;
                    return newToken(buf);
                }else{
                    //write character to buf
                    buf[++ptr] = c;
                }
            }
        }
    }
    if(ptr){
        buf[ptr+1]=0;
        return newToken(buf);
    }else{
        return NULL;
    }
}

/**
 *
 * @param src readable source file to be assembled
 * @param dst writeable destination file for binary
 */
int parse(FILE *src, FILE *dst) {
    TOKEN *tok;
    OPCODE ins;
    while ((tok = getToken(src))) {
        switch (tok->payload) {
            case IMM:
            case IND:
            case NOP:
            case REV:
            case HLT:
                ins = tok->payload;
                break;
            case MOV:
                tok = getToken(src);
                assert(tok != NULL && tok->payload < 16);
                ins = tok->payload << (unsigned) 4;
                tok = getToken(src);
                assert(tok != NULL && tok->payload < 16);
                ins |= tok->payload;
                break;
            default:
                fprintf(stderr, "unexpected token in stream\n");
                return 1; // should never be the case
        }
        if(EOF == fputc(ins, dst)){
            fprintf(stderr, "error writing to file\n");
            return 1;
        }
    }
    return 0;
}

int launch_asmblr(const char *input, const char *output){
    FILE *src, *dst;
    src = fopen(input, "r");
    dst = fopen(output, "w+");
    assert(src);
    assert(dst);
    return parse(src, dst);
}