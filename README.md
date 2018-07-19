# asmblr-git

---

### Purpose
git repo for an assembler and machine simulator of a relay based computer to be built later

---

### Assembler Syntax

```
MOV x y  => x,y are single digit hexadecimal numbers referring to registers
IMM      := MOV A 0
IND      := MOV A F
NOP      := MOV 1 1
REV      := MOV 2 1
HLT      := MOV 0 0
```

Comments delimited by `';'` and `'\n'`
