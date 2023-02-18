cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(BENCH_TCMALLOC_PROJECT ${PROJ_NAME}_tcmalloc)

option(BUILD_TESTING OFF)
add_subdirectory(${PROJECT_ROOT_DIR}/third_party/tcmalloc ${BENCH_TCMALLOC_PROJECT}/tcmalloc)

add_executable(${BENCH_TCMALLOC_PROJECT} ${SOURCES_FILES})