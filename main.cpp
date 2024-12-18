#include <iostream>
#include <vector>
#include <numeric>
#include <likwid.h>

int main() {
    const int size = 102400;
    std::vector<double> a(size);
    std::vector<double> b(size, 2.0);
    std::vector<double> c(size, 3.0);

    LIKWID_MARKER_INIT;

    LIKWID_MARKER_REGISTER("add_loop");

    LIKWID_MARKER_START("add_loop");
    for (int i = 0; i < size; ++i) {
        a[i] = b[i] + c[i];
    }
    LIKWID_MARKER_STOP("add_loop");

    double sum = std::accumulate(a.begin(), a.end(), 0.0);
    std::cout << "Sum: " << sum << std::endl;

    LIKWID_MARKER_CLOSE;

    return 0;
}

