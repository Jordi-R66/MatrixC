#!/bin/bash

gcc -Wall -m64 -march=x86-64 -std=c23 -Oz -s -masm=intel gauss.c matrix.c test.c -o test_x86-64.elf
gcc -Wall -m32 -march=i386 -std=c23 -Oz -s -masm=intel gauss.c matrix.c test.c -o test_i386.elf

gcc -std=c23 -S -Oz -s -masm=intel gauss.c matrix.c test.c