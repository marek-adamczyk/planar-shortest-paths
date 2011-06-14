
add_library(planarity 
graphColorVertices.c             graphIO.c                    graphK4Search_Extensions.c     planarityCommandLine.c
graphColorVertices_Extensions.c  graphIsolator.c              graphNonplanar.c               planarityRandomGraphs.c
graphDFSUtils.c                  graphK23Search.c             graphOuterplanarObstruction.c  planaritySpecificGraph.c
graphDrawPlanar.c                graphK23Search_Extensions.c  graphTests.c                   planarityUtils.c
graphDrawPlanar_Extensions.c     graphK33Search.c             graphUtils.c                   stack.c
graphEmbed.c                     graphK33Search_Extensions.c  listcoll.c
graphExtensions.c                graphK4Search.c              
)

add_executable(planarity_test planarity.c)
target_link_libraries(planarity_test planarity nauty common ${CORELIBS} )





add_subdirectory(nauty)
add_subdirectory(test)
