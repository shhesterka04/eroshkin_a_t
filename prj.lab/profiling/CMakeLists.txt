add_library(profiling profiling.h profiling.cpp)

add_executable(main main.cpp)
target_link_libraries(main profiling)