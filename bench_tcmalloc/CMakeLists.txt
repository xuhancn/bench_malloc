cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(BENCH_TCMALLOC_PROJECT ${PROJ_NAME}_tcmalloc)

option(BUILD_TESTING OFF)
add_subdirectory(${PROJECT_ROOT_DIR}/third_party/tcmalloc ${BENCH_TCMALLOC_PROJECT}/tcmalloc)

set(TCMALLOC_LIB_PATH
    "$<$<CONFIG:Debug>:"
        "${LIBRARY_OUTPUT_PATH}/Debug/"
    ">"
    "$<$<NOT:$<CONFIG:Debug>>:"
        "${LIBRARY_OUTPUT_PATH}/Release/"
    ">"
)
link_directories(${TCMALLOC_LIB_PATH})

add_executable(${BENCH_TCMALLOC_PROJECT} ${SOURCES_FILES})

set_target_properties(${BENCH_TCMALLOC_PROJECT} PROPERTIES LINK_FLAGS /INCLUDE:"__tcmalloc")
target_link_libraries(${BENCH_TCMALLOC_PROJECT} PRIVATE "logging.lib")
target_link_libraries(${BENCH_TCMALLOC_PROJECT} PRIVATE "spinlock.lib")
target_link_libraries(${BENCH_TCMALLOC_PROJECT} PRIVATE "sysinfo.lib")
target_link_libraries(${BENCH_TCMALLOC_PROJECT} PRIVATE "tcmalloc_minimal_static.lib")