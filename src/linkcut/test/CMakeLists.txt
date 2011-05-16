
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_BIN_DIR})

add_executable(splay_reverse_test splay_reverse_test.cpp)
target_link_libraries(splay_reverse_test linkcut common ${CORELIBS} )
add_test(splay_reverse_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/splay_reverse_test ${TEST_SUFFIX})

add_executable(linkcut_test linkcut_test.cpp)
target_link_libraries(linkcut_test linkcut common ${CORELIBS} )
add_test(linkcut_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/linkcut_test ${TEST_SUFFIX})

