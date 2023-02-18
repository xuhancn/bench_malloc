cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(PROJ_NAME "bench_malloc")
project (${PROJ_NAME})

set(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${PROJECT_ROOT_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_ROOT_DIR}/bin)

set(SOURCES_FILES)
add_subdirectory(${PROJECT_ROOT_DIR}/src)

# built-in malloc
add_executable(${PROJ_NAME} ${SOURCES_FILES})

# tcmalloc
add_subdirectory(${PROJECT_ROOT_DIR}/bench_tcmalloc)