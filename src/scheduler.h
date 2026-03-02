#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
} Process;

void run_fcfs(Process *procs, int n);
void run_round_robin(Process *procs, int n, int quantum);

#endif