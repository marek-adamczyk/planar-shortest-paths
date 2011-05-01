cmake_minimum_required (VERSION 2.6)
project (Planar-shortest-paths)
enable_testing()

include_directories(SYSTEM /usr/include/graphviz)
set(CORELIBS ${CORELIBS} gvc graph cdt)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(TEST_BIN_DIR "test")



add_subdirectory(src)
