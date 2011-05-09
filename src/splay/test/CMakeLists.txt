
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_BIN_DIR})

add_executable(splay_test splay_test.cpp)
target_link_libraries(splay_test splay common ${CORELIBS} )
add_test(splay_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/splay_test ${TEST_SUFFIX})

