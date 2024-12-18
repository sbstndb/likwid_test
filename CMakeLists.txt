# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(TestLIKWIDMarkers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native -mtune=native ")

# Trouver les bibliothèques LIKWID
find_package(Likwid REQUIRED)



# Inclure les répertoires LIKWID
include_directories(${LIKWID_INCLUDE_DIRS})

# Ajouter l'exécutable
add_executable(test_likwid_markers main.cpp)

# Lier les bibliothèques LIKWID
target_link_libraries(test_likwid_markers ${LIKWID_LIBRARIES})

