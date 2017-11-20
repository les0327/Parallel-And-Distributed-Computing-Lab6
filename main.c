#include <stdio.h>
#include "functions.h"
#include <mpi.h>

/**
 Parallel and distributed computing.
 Lab 5. Threads in OpenMP
 Lisovyi Volodymyr
 IO-53
 30.10.17
 F1: e = (A*B) + (C*(D*(MA*MD)))
 F2: ML = SORT(MF + MG*MH)
 F3: O = MAX(MP*MR)*T
 */
int main(int argc, char *argv[]) {
    printf("Main start\n");

    MPI_Comm my_comm;
    MPI_Group my_group;
    MPI_Init(&argc, &argv);
    int tid;
    MPI_Comm_group(MPI_COMM_WORLD, &my_group);
    MPI_Comm_create(MPI_COMM_WORLD, my_group, &my_comm);
    MPI_Comm_rank(my_comm, &tid);
    switch (tid) {
        case 0:
            threadFunction1();
            break;
        case 1:
            threadFunction2();
            break;
        case 2:
            threadFunction3();
            break;
    }
    MPI_Finalize();

    printf("Main finish\n");
    return 0;
}

