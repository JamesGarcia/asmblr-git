cmake_minimum_required(VERSION 3.10)
project(archsim C)

set(CMAKE_C_STANDARD 99)

add_executable(archsim src/main.c src/asmblr.c src/asmblr.h src/asmsim.c src/asmsim.h src/lib/args.c src/lib/args.h src/lib/queue.c src/lib/queue.h)