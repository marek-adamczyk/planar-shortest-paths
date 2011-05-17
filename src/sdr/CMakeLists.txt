
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/../src/sdr/)

add_executable(sdr sdr.cpp)
target_link_libraries(sdr linkcut common ${CORELIBS} )
add_test(sdr ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sdr ${TEST_SUFFIX})

