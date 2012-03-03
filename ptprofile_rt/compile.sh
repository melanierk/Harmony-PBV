clang -O3 -emit-llvm -c -o ptprofile.bc ptprofile.c
clang -O0 -ggdb -emit-llvm -c -o ptprofile_debug.bc ptprofile.c
