1

cd /home/runner/oslab2019/lab3/src
pwd
gcc sequential_min_max.c find_min_max.c utils.c -o find
./find 1 90

2-3

 gcc parallel_min_max.c find_min_max.c utils.c -o parallel
 ./parallel --seed 1 --array_size 6000 --pnum 2


Min: 100669
Max: 2147469841
Elapsed time: 3.115000ms

./parallel --seed 1 --array_size 60000 --pnum 2


Min: 3722
Max: 2147469841
Elapsed time: 0.761000ms

./parallel --seed 1 --array_size 60000 --pnum 2 --by_files


Min: 3722
Max: 2147469841
Elapsed time: 1.619000ms

4

make
  gcc -o utils.o -c utils.c -I.
  gcc -o find_min_max.o -c find_min_max.c -I.
  gcc -o sequential_min_max find_min_max.o utils.o sequential_min_max.c -I.
  gcc -o parallel_min_max utils.o find_min_max.o parallel_min_max.c -I.
make clean
  rm utils.o find_min_max.o sequential_min_max parallel_min_max
 
 5 
 exec вытягивает функцию из мейкфайла

 gcc exec.c
 make
 ./a.out
 