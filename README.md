# Mini OS Scheduler Simulator (C)

A lightweight CPU scheduling simulator written in C. This project models processes with **arrival times** and **CPU burst times**, runs scheduling policies, and prints an execution **timeline** to show how the CPU is allocated over time.

This is a small “systems-style” project that demonstrates scheduling logic, basic simulation design, and low-level C programming.

---

## Table of Contents
- [What this project does](#what-this-project-does)
- [Scheduling policies implemented](#scheduling-policies-implemented)
- [Input format](#input-format)
- [How to build](#how-to-build)
  - [Build on Windows (MSYS2 UCRT64)](#build-on-windows-msys2-ucrt64)
  - [Build on Linux/macOS](#build-on-linuxmacos)
- [How to run](#how-to-run)
- [Understanding the output](#understanding-the-output)
- [Project structure](#project-structure)
- [Design notes](#design-notes)
- [Troubleshooting](#troubleshooting)
- [Future improvements](#future-improvements)
- [License](#license)

---

## What this project does

Real operating systems must decide **which process runs next** on the CPU. Different scheduling policies optimize for different goals (fairness, responsiveness, throughput, etc.).

This simulator:
1. Reads a list of processes from an input file
2. Simulates CPU execution under a chosen scheduling algorithm
3. Prints a **timeline** showing which process is running at each time unit

---

## Scheduling policies implemented

### 1) FCFS (First Come First Serve)
- Non-preemptive
- The CPU runs processes in order of **arrival time**
- Once a process starts, it runs until completion

**Pros:** simple  
**Cons:** can cause poor responsiveness (long process blocks everyone behind it)

---

### 2) Round Robin (RR)
- Preemptive
- Each process receives a fixed time slice called a **quantum**
- After `quantum` time units, the scheduler switches to the next process (if the current process is not finished)

**Pros:** fair and responsive  
**Cons:** too small a quantum increases switching overhead (in real OS)

---

## Input format

Input files are plain text.

**First line:** number of processes `n`  
**Next `n` lines:** `pid arrival_time burst_time`

Example (`test/sample.txt`):

```txt
4
1 0 5
2 1 3
3 2 2
4 4 4
