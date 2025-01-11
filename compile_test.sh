#!/bin/bash

gcc -Wall -std=c17 -Oz -s -masm=intel gauss.c matrix.c test.c -o test.elf
gcc -std=c17 -S -Oz -s -masm=intel gauss.c matrix.c test.c