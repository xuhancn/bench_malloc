cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(BENCH_TCMALLOC_PROJECT ${PROJ_NAME}_tcmalloc)

project(${BENCH_TCMALLOC_PROJECT})

option(BUILD_TESTING OFF)
add_subdirectory(${PROJECT_ROOT_DIR}/third_party/tcmalloc ${BENCH_TCMALLOC_PROJECT}/tcmalloc)

if(MSVC)
set(TCMALLOC_LIB_PATH
    "$<$<CONFIG:Debug>:"
        "${LIBRARY_OUTPUT_PATH}/Debug/"
    ">"
    "$<$<NOT:$<CONFIG:Debug>>:"
        "${LIBRARY_OUTPUT_PATH}/Release/"
    ">"
)
link_directories(${TCMALLOC_LIB_PATH})
endif()

add_executable(${BENCH_TCMALLOC_PROJECT} ${SOURCES_FILES})

if(MSVC)
set_target_properties(${BENCH_TCMALLOC_PROJECT} PROPERTIES LINK_FLAGS /INCLUDE:"__tcmalloc")
target_link_libraries(${BENCH_TCMALLOC_PROJECT} PRIVATE "logging.lib")
target_link_libraries(${BENCH_TCMALLOC_PROJECT} PRIVATE "spinlock.lib")
target_link_libraries(${BENCH_TCMALLOC_PROJECT} PRIVATE "sysinfo.lib")
target_link_libraries(${BENCH_TCMALLOC_PROJECT} PRIVATE "tcmalloc_minimal_static.lib")
add_dependencies(${BENCH_TCMALLOC_PROJECT} tcmalloc_minimal_static)
else()
target_link_libraries(${BENCH_TCMALLOC_PROJECT} ${LIBRARY_OUTPUT_PATH}/libtcmalloc_minimal.a)
endif()