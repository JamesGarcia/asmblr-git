#ifndef ARCHSIM_ERRCODES_H
#define ARCHSIM_ERRCODES_H

#define NOERR   0x000
#define BRESET  0x001
#define TRESET  0x002
#define LRESET  0x004
#define PRESET  0x008
#define PUNSET  0x010
#define NOARG   0x020
#define BADOPT  0x040
#define BADSYN  0x080
#define MAXERR  0x100

#define PRINT_ERR "Fatal error in asmsim when locating internal file %s\n"

void clear_error();
void raise_error(int cond, int err);
void add_error(int err);
void test_error();

#endif //ARCHSIM_ERRCODES_H
