#ifndef ARCHSIM_TEXT_H
#define ARCHSIM_TEXT_H

char const * const manual_doc =                                "\
----------------------------------------------------------------\n\
ArchSim                                                         \n\
@author    JamesGarcia                                          \n\
@version   1.0.0                                                \n\
----------------------------------------------------------------\n\
Options:                                                        \n\
  -b           output intermediate bytecode as out.bc           \n\
  -B <name>    output intermediate bytecode as <name>.bc        \n\
  -t           output resulting tape of bytecode as prog.tp     \n\
  -T <name>    output resulting tape of bytecode as <name>.tp   \n\
  -l           log runtime view of simulation to sim.log        \n\
  -L <name>    log runtime view of simulation to <name>.log     \n\
  -i <file>    read input from <file>                           \n\
  -o <file>    write output to <file>                           \n\
  -v           view simulation while in progress                \n\
  -x           do not run simulation                            \n\
  -h           display help and information                     \n\
----------------------------------------------------------------\n";

char const * const error_doc =                                 "\
----------------------------------------------------------------\n\
Error encoding:                                                 \n\
  0x0001       multiple destinations for intermediate bytecode  \n\
  0x0002       multiple destinations for tape bytecode          \n\
  0x0004       multiple destinations for simulation log         \n\
  0x0008       multiple input files                             \n\
  0x0010       no input file                                    \n\
  0x0020       argument missing for option requiring an argument\n\
  0x0040       unknown option                                   \n\
  0x0080       one or more options conflict with one another    \n\
  0x0100       fatal error                                      \n\
----------------------------------------------------------------\n";

#endif //ARCHSIM_TEXT_H