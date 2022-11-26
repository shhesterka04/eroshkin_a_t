add_subdirectory(complex)
add_subdirectory(rational)
add_subdirectory(bitset)
add_subdirectory(bitsetT)
add_subdirectory(qu)
add_subdirectory(bitsetI)
add_subdirectory(bitsetD)
add_subdirectory(queueR)
add_subdirectory(queueP)
add_subdirectory(profiling)

include(FetchContent)
FetchContent_Declare(matplotplusplus
GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
GIT_TAG origin/master)
FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
FetchContent_Populate(matplotplusplus)
add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

target_link_libraries(profiling PUBLIC matplot)