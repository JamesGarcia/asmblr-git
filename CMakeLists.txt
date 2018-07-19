cmake_minimum_required(VERSION 3.10)
project(archsim C)

set(CMAKE_C_STANDARD 99)

add_executable(archsim src/main.c src/asmblr.c src/asmblr.h src/asmsim.c src/asmsim.h src/lib/args.c src/lib/args.h src/lib/queue.c src/lib/queue.h src/lib/fixed_dict.c src/lib/fixed_dict.h src/lib/list.c src/lib/list.h src/client.c src/error.h src/error.c src/text.h src/args_handler.c src/args_handler.h src/assembler.c src/assembler.h src/simulator.c src/simulator.h)