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
Here is the output of the command `likwid-perfctr -C 1 -g FLOPS_DP -m ./test_likwid_markers`. It gives `FLOPS_DP` results for each region. 

```bash
--------------------------------------------------------------------------------
CPU name:	AMD Ryzen 9 3900X 12-Core Processor            
CPU type:	AMD K17 (Zen2) architecture
CPU clock:	3.79 GHz
--------------------------------------------------------------------------------
Sum: 2.1504e+06
--------------------------------------------------------------------------------
Region add_loop, Group 1: FLOPS_DP
+-------------------+------------+
|    Region Info    | HWThread 1 |
+-------------------+------------+
| RDTSC Runtime [s] |   0.000026 |
|     call count    |          1 |
+-------------------+------------+

+---------------------------+---------+-----------------+
|           Event           | Counter |    HWThread 1   |
+---------------------------+---------+-----------------+
|      ACTUAL_CPU_CLOCK     |  FIXC1  |               0 |
|       MAX_CPU_CLOCK       |  FIXC2  |               0 |
|    RETIRED_INSTRUCTIONS   |   PMC0  |          157538 |
|    CPU_CLOCKS_UNHALTED    |   PMC1  |         2040080 |
| RETIRED_SSE_AVX_FLOPS_ALL |   PMC2  |          102410 |
|           MERGE           |   PMC3  | 562950000000000 |
+---------------------------+---------+-----------------+

+----------------------+--------------+
|        Metric        |  HWThread 1  |
+----------------------+--------------+
|  Runtime (RDTSC) [s] | 2.609904e-05 |
| Runtime unhalted [s] |            0 |
|      Clock [MHz]     |       -      |
|          CPI         |      12.9498 |
|     DP [MFLOP/s]     |    3923.8991 |
+----------------------+--------------+

Region add_loop_unrolled, Group 1: FLOPS_DP
+-------------------+------------+
|    Region Info    | HWThread 1 |
+-------------------+------------+
| RDTSC Runtime [s] |   0.000029 |
|     call count    |          1 |
+-------------------+------------+


+---------------------------+---------+-----------------+
|           Event           | Counter |    HWThread 1   |
+---------------------------+---------+-----------------+
|      ACTUAL_CPU_CLOCK     |  FIXC1  |               0 |
|       MAX_CPU_CLOCK       |  FIXC2  |               0 |
|    RETIRED_INSTRUCTIONS   |   PMC0  |          159040 |
|    CPU_CLOCKS_UNHALTED    |   PMC1  |         1794032 |
| RETIRED_SSE_AVX_FLOPS_ALL |   PMC2  |          102410 |
|           MERGE           |   PMC3  | 562950000000000 |
+---------------------------+---------+-----------------+

+----------------------+--------------+
|        Metric        |  HWThread 1  |
+----------------------+--------------+
|  Runtime (RDTSC) [s] | 2.299358e-05 |
| Runtime unhalted [s] |            0 |
|      Clock [MHz]     |       -      |
|          CPI         |      11.2804 |
|     DP [MFLOP/s]     |    4453.8519 |
+----------------------+--------------+

Region add_loop_unrolled8, Group 1: FLOPS_DP
+-------------------+------------+
|    Region Info    | HWThread 1 |
+-------------------+------------+
| RDTSC Runtime [s] |   0.000025 |
|     call count    |          1 |
+-------------------+------------+

+---------------------------+---------+-----------------+
|           Event           | Counter |    HWThread 1   |
+---------------------------+---------+-----------------+
|      ACTUAL_CPU_CLOCK     |  FIXC1  |               0 |
|       MAX_CPU_CLOCK       |  FIXC2  |               0 |
|    RETIRED_INSTRUCTIONS   |   PMC0  |          120742 |
|    CPU_CLOCKS_UNHALTED    |   PMC1  |         1840016 |
| RETIRED_SSE_AVX_FLOPS_ALL |   PMC2  |          102410 |
|           MERGE           |   PMC3  | 562950000000000 |
+---------------------------+---------+-----------------+

+----------------------+--------------+
|        Metric        |  HWThread 1  |
+----------------------+--------------+
|  Runtime (RDTSC) [s] | 2.472686e-05 |
| Runtime unhalted [s] |            0 |
|      Clock [MHz]     |       -      |
|          CPI         |      15.2392 |
|     DP [MFLOP/s]     |    4141.6500 |
+----------------------+--------------+

```



