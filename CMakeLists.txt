cmake_minimum_required (VERSION 2.6)

project (Planar-shortest-paths)
enable_testing()

include_directories(SYSTEM /usr/include/graphviz)
set(CORELIBS ${CORELIBS} gvc graph cdt)

add_subdirectory(src)
