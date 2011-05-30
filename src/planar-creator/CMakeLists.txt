
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_BIN_DIR}/planar-creator/)

add_executable(planar-creator planar-creator.cpp)
target_link_libraries(planar-creator /home/marro/mgr/ogdf/OGDF/_release/libOGDF.a linkcut common ${CORELIBS} )
add_test(planar-creator ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/planar-creator_test ${TEST_SUFFIX})

