#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scheduler.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage:\n");
        printf("  scheduler <input_file> fcfs\n");
        printf("  scheduler <input_file> rr <quantum>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    Process *procs = malloc(sizeof(Process) * n);

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %d %d", 
               &procs[i].pid,
               &procs[i].arrival,
               &procs[i].burst);
        procs[i].remaining = procs[i].burst;
    }

    fclose(file);

    if (strcmp(argv[2], "fcfs") == 0) {
        run_fcfs(procs, n);
    } else if (strcmp(argv[2], "rr") == 0) {
        int quantum = atoi(argv[3]);
        run_round_robin(procs, n, quantum);
    }

    free(procs);
    return 0;
}