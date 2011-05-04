
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_BIN_DIR})

add_executable(linkcut_test linkcut_test.c)
target_link_libraries(linkcut_test linkcut common ${CORELIBS} )
add_test(linkcut_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/linkcut_test ${TEST_SUFFIX})

