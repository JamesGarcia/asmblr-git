#include <stdio.h>
#include <process.h>
#include "text.h"
#include "error.h"

static int errval;

void clear_error(){
    errval = NOERR;
}
void raise_error(int cond, int err){
    if(cond) errval |= err;
}
void add_error(int err){
    errval |= err;
}
void test_error(){
    if(errval){
        printf("!!! asmsim exited with error code: 0x%04X\n", errval);
        printf(error_doc);
        exit(1);
    }
}

