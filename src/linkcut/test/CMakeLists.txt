
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_BIN_DIR})

add_executable(splay_lc_test splay_test.cpp)
target_link_libraries(splay_lc_test linkcut common ${CORELIBS} )
add_test(splay_lc_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/splay_lc_test ${TEST_SUFFIX})

add_executable(linkcut_test linkcut_test.cpp)
target_link_libraries(linkcut_test linkcut common ${CORELIBS} )
add_test(linkcut_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/linkcut_test ${TEST_SUFFIX})

