
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_BIN_DIR})

add_executable(random-planar_test random-planar_test.cpp)
target_link_libraries(random-planar_test planarity common ${CORELIBS} )
add_test(random-planar_test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/random-planar_test ${TEST_SUFFIX})


