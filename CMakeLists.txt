cmake_minimum_required(VERSION 3.27)
project(CS392)

set(CMAKE_CXX_STANDARD 14)

include_directories(hw2/hw2_starter_code)
include_directories(hw3)
include_directories(hw3/submission)
include_directories(hw3/submission2.o)

add_executable(CS392
        hw2/hw2_starter_code/submission/bubble.c
        hw2/hw2_starter_code/submission/utils.c
        hw2/hw2_starter_code/bubble.c
        hw2/hw2_starter_code/bubble.h
        hw2/hw2_starter_code/main.c
        hw2/hw2_starter_code/utils.c
        hw2/hw2_starter_code/utils.h
        hw3/submission/main.c
        hw3/submission/oocmerge.c
        hw3/submission/oocmerge.h
        hw3/submission2.o/main.c
        hw3/submission2.o/oocmerge.c
        hw3/submission2.o/oocmerge.h
        hw3/main.c
        hw3/oocmerge.c
        hw3/oocmerge.h
        hw3.2/main.c
        hw4/makefile
        hw4/maxfile.c
        labs/lab5/fork_intro.c
        labs/lab5/lab5_fork.c
        "labs/lab2_fn_pointers (1).c"
        labs/lab2_fn_pointers.c
        labs/lab3_files.c
        labs/lab6/lab6_nforks.c
        labs/lab6/randomleep2.c
        labs/lab7/lab7_prompt.c
        hw5/msh.c
        hw5/harris.c
        hw5/harris.c
        hw5/sighandler.c
        hw5/sighandler.h)
