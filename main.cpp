#include <iostream>
#include <vector>
#include <numeric>
#include <likwid.h>

#ifdef LIKWID_PERFMON
#include <likwid-marker.h>
#else
#define LIKWID_MARKER_INIT
#define LIKWID_MARKER_THREADINIT
#define LIKWID_MARKER_SWITCH
#define LIKWID_MARKER_REGISTER(regionTag)
#define LIKWID_MARKER_START(regionTag)
#define LIKWID_MARKER_STOP(regionTag)
#define LIKWID_MARKER_CLOSE
#define LIKWID_MARKER_GET(regionTag, nevents, events, time, count)
#endif

int main() {
    const int size = 102400;
    std::vector<double> a(size);
    std::vector<double> b(size, 2.0);
    std::vector<double> c(size, 3.0);

    LIKWID_MARKER_INIT;

    LIKWID_MARKER_REGISTER("add_loop");
    LIKWID_MARKER_REGISTER("add_loop_unrolled");    
    LIKWID_MARKER_REGISTER("add_loop_unrolled8");


    for (int i = 0; i < size; ++i) {
        a[i] = b[i] + c[i];
    }

    LIKWID_MARKER_START("add_loop");
    for (int i = 0; i < size; ++i) {
        b[i] = c[i] + a[i];
    }
    LIKWID_MARKER_STOP("add_loop");

    LIKWID_MARKER_START("add_loop_unrolled");
    for (int i = 0; i < size;i+=2) {
        c[i] = a[i] + b[i];
	c[i+1] = a[i+1] + b[i+1];
    }
    LIKWID_MARKER_STOP("add_loop_unrolled");

    LIKWID_MARKER_START("add_loop_unrolled8");
    for (int i = 0; i < size;i+=8) {
        a[i]   = b[i]   + c[i];
        a[i+1] = b[i+1] + c[i+1];
        a[i+2] = b[i+2] + c[i+2];
        a[i+3] = b[i+3] + c[i+3];
        a[i+4] = b[i+4] + c[i+4];
        a[i+5] = b[i+5] + c[i+5];
        a[i+6] = b[i+6] + c[i+6];
        a[i+7] = b[i+7] + c[i+7];


    }
    LIKWID_MARKER_STOP("add_loop_unrolled8");

    double sum = std::accumulate(a.begin(), a.end(), 0.0);
    std::cout << "Sum: " << sum << std::endl;

    LIKWID_MARKER_CLOSE;

    return 0;
}

