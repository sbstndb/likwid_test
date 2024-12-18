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


