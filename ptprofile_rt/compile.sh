rm *.bc
clang -O3 -emit-llvm -c -o ptprofile.bc ptprofile.c
clang -O3 -emit-llvm -c -DPROF_MAX_THREADS=64 -o ptprofile_64threads.bc ptprofile.c
clang -O0 -ggdb -emit-llvm -c -o ptprofile_debug.bc ptprofile.c
clang -DPROF_W -O3 -emit-llvm -c -o ptprofile_w.bc ptprofile.c
clang -DPROF_W -O0 -ggdb -emit-llvm -c -o ptprofile_w_debug.bc ptprofile.c
