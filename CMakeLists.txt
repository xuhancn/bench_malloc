cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(PROJ_NAME "bench_malloc")
project (${PROJ_NAME})

set(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})

set(SOURCES_FILES)
add_subdirectory(${PROJECT_ROOT_DIR}/src)

add_executable(${PROJ_NAME} ${SOURCES_FILES})