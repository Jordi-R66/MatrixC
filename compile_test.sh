#!/bin/bash

clear

SRC_FILES="advMatrix.c tracking.c gauss.c matrix.c test.c"
ASM_FILES="advMatrix.s tracking.s gauss.s matrix.s test.s"

ASM_SYNTAX="-masm=intel"
OPTIMIZATION="-O0"

C_DIALECT="-std=c23"

echo "Compiling for x86-64"
gcc -g -w -D __64_BITS__ -m64 -march=x86-64 $C_DIALECT $OPTIMIZATION $ASM_SYNTAX $SRC_FILES -o test_x86-64.elf

echo "Compiling for i386"
gcc -g -w -D __32_BITS__ -m32 -march=i386 $C_DIALECT $OPTIMIZATION $ASM_SYNTAX $SRC_FILES -o test_i386.elf

echo ""

mkdir x86-64
mkdir i386

echo ""
echo "Generating assembly files for x86-64"

gcc -g -w -D __64_BITS__ -m64 -march=x86-64 $C_DIALECT $OPTIMIZATION $ASM_SYNTAX $SRC_FILES -S
mv $ASM_FILES x86-64/
mv test_x86-64.elf x86-64/

echo "Generating assembly files for i386"

gcc -g -w -D __32_BITS__ -m32 -march=i386 $C_DIALECT $OPTIMIZATION $ASM_SYNTAX $SRC_FILES -S
mv $ASM_FILES i386/
mv test_i386.elf i386/

echo "ASM Files generated"
echo ""

file x86-64/* i386/*