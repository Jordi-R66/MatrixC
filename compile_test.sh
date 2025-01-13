#!/bin/bash

clear

echo "Compiling for x86-64"
gcc -w -m64 -march=x86-64 -std=c23 -O0 -masm=intel gauss.c matrix.c test.c -o test_x86-64.elf

echo "Compiling for i386"
gcc -w -m32 -march=i386 -std=c23 -O0 -masm=intel gauss.c matrix.c test.c -o test_i386.elf

echo ""

mkdir x86-64
mkdir i386

echo ""
echo "Generating assembly files for x86-64"

gcc -w -m64 -march=x86-64 -std=c23 -O0 -masm=intel -S gauss.c matrix.c test.c
mv gauss.s matrix.s test.s test_x86-64.elf x86-64

echo "Generating assembly files for i386"

gcc -w -m32 -march=i386 -std=c23 -O0 -masm=intel -S gauss.c matrix.c test.c
mv gauss.s matrix.s test.s test_i386.elf i386

echo "ASM Files generated"
echo ""

file x86-64/* i386/*
