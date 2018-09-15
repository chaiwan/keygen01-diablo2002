#!/bin/sh -
target=keygen
gcc -pie -march=native -O3 -std=gnu18 $@ -o $target $target.c && strip --strip-unneeded ./$target && echo ok!
