# LIKWID Profiling Example
This project demonstrates how to use LIKWID (a performance monitoring tool) to profile specific sections of a C++ program. The program calculates vector sums while using LIKWID markers to measure performance during specific code regions.

# Features
- LIKWID Markers to profile code regions
- Measures FLOPS (Floating Point Operations Per Second) and other metrics like Branch-misses

# Requirements
- LIKWID library installed with your package manager 
- A recent c++11 compiler

# Compilation
use CMake to configure and build the project:
```bash
cmake -B build -S . 
cmake --build build
cd build 
```

# Usage
Run the compiler program with or without metric API: 
```bash
# First option : launch the standalone program 
./test_likwid_markers
# Second option : launch metrics 
likwid-perfctr -C 1 -g FLOPS_DP -m ./test_likwid_markers
# Third option : launch script
../likwid-perfctr.sh
```

# Result
Here is the output of the command `likwid-perfctr -C 2 -g BRANCH -m ./test_likwid_markers`. It gives `FLOPS_DP` results for each region. 

```bash
--------------------------------------------------------------------------------
CPU name:	AMD Ryzen 9 3900X 12-Core Processor            
CPU type:	AMD K17 (Zen2) architecture
CPU clock:	3.79 GHz
--------------------------------------------------------------------------------
Sum: 2.1504e+06
--------------------------------------------------------------------------------
Region add_loop, Group 1: BRANCH
+-------------------+------------+
|    Region Info    | HWThread 1 |
+-------------------+------------+
| RDTSC Runtime [s] |   0.000029 |
|     call count    |          1 |
+-------------------+------------+

+---------------------------+---------+------------+
|           Event           | Counter | HWThread 1 |
+---------------------------+---------+------------+
|      ACTUAL_CPU_CLOCK     |  FIXC1  |          0 |
|       MAX_CPU_CLOCK       |  FIXC2  |          0 |
|    RETIRED_INSTRUCTIONS   |   PMC0  |     157527 |
|    CPU_CLOCKS_UNHALTED    |   PMC1  |     111323 |
|    RETIRED_BRANCH_INSTR   |   PMC2  |      26402 |
| RETIRED_MISP_BRANCH_INSTR |   PMC3  |       1072 |
+---------------------------+---------+------------+

+----------------------------+--------------+
|           Metric           |  HWThread 1  |
+----------------------------+--------------+
|     Runtime (RDTSC) [s]    | 2.927494e-05 |
|    Runtime unhalted [s]    |            0 |
|         Clock [MHz]        |       -      |
|             CPI            |       0.7067 |
|         Branch rate        |       0.1676 |
|  Branch misprediction rate |       0.0068 |
| Branch misprediction ratio |       0.0406 |
|   Instructions per branch  |       5.9665 |
+----------------------------+--------------+

Region add_loop_unrolled, Group 1: BRANCH
+-------------------+------------+
|    Region Info    | HWThread 1 |
+-------------------+------------+
| RDTSC Runtime [s] |   0.000026 |
|     call count    |          1 |
+-------------------+------------+

+---------------------------+---------+------------+
|           Event           | Counter | HWThread 1 |
+---------------------------+---------+------------+
|      ACTUAL_CPU_CLOCK     |  FIXC1  |          0 |
|       MAX_CPU_CLOCK       |  FIXC2  |          0 |
|    RETIRED_INSTRUCTIONS   |   PMC0  |     159040 |
|    CPU_CLOCKS_UNHALTED    |   PMC1  |     108462 |
|    RETIRED_BRANCH_INSTR   |   PMC2  |      26745 |
| RETIRED_MISP_BRANCH_INSTR |   PMC3  |        848 |
+---------------------------+---------+------------+

+----------------------------+--------------+
|           Metric           |  HWThread 1  |
+----------------------------+--------------+
|     Runtime (RDTSC) [s]    | 2.579842e-05 |
|    Runtime unhalted [s]    |            0 |
|         Clock [MHz]        |       -      |
|             CPI            |       0.6820 |
|         Branch rate        |       0.1682 |
|  Branch misprediction rate |       0.0053 |
| Branch misprediction ratio |       0.0317 |
|   Instructions per branch  |       5.9465 |
+----------------------------+--------------+

Region add_loop_unrolled8, Group 1: BRANCH
+-------------------+------------+
|    Region Info    | HWThread 1 |
+-------------------+------------+
| RDTSC Runtime [s] |   0.000024 |
|     call count    |          1 |
+-------------------+------------+

+---------------------------+---------+------------+
|           Event           | Counter | HWThread 1 |
+---------------------------+---------+------------+
|      ACTUAL_CPU_CLOCK     |  FIXC1  |          0 |
|       MAX_CPU_CLOCK       |  FIXC2  |          0 |
|    RETIRED_INSTRUCTIONS   |   PMC0  |     120689 |
|    CPU_CLOCKS_UNHALTED    |   PMC1  |     109243 |
|    RETIRED_BRANCH_INSTR   |   PMC2  |      13964 |
| RETIRED_MISP_BRANCH_INSTR |   PMC3  |        816 |
+---------------------------+---------+------------+

+----------------------------+--------------+
|           Metric           |  HWThread 1  |
+----------------------------+--------------+
|     Runtime (RDTSC) [s]    | 2.360430e-05 |
|    Runtime unhalted [s]    |            0 |
|         Clock [MHz]        |       -      |
|             CPI            |       0.9052 |
|         Branch rate        |       0.1157 |
|  Branch misprediction rate |       0.0068 |
| Branch misprediction ratio |       0.0584 |
|   Instructions per branch  |       8.6429 |
+----------------------------+--------------+
```

As you can see, while there is a for loop for 102k elements,
- the first loop has 26k branches
- the second loop (unrolled 2) has 26k branches
- the third loop (unrolled 8) has 14k branches

This is because my compiler unroll the loop by a factor of 4 for the two first cases. The last case is way too unrolled : even the compiler don't want to go that deep. 
Anyway, this LIKWID tool helps you identify bad branch or branch-miss regions. 




