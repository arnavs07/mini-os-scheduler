#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

void run_fcfs(Process *procs, int n) {
    int time = 0;

    printf("\n=== FCFS ===\nTimeline: ");

    for (int i = 0; i < n; i++) {
        if (time < procs[i].arrival) {
            while (time < procs[i].arrival) {
                printf("idle ");
                time++;
            }
        }

        for (int j = 0; j < procs[i].burst; j++) {
            printf("P%d ", procs[i].pid);
            time++;
        }
    }

    printf("\n");
}

void run_round_robin(Process *procs, int n, int quantum) {
    int done = 0;
    int time = 0;

    printf("\n=== Round Robin (q=%d) ===\nTimeline: ", quantum);

    while (!done) {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (procs[i].remaining > 0) {
                done = 0;

                int slice = quantum;
                if (procs[i].remaining < quantum)
                    slice = procs[i].remaining;

                for (int j = 0; j < slice; j++) {
                    printf("P%d ", procs[i].pid);
                    time++;
                }

                procs[i].remaining -= slice;
            }
        }
    }

    printf("\n");
}