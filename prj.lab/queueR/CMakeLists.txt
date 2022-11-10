add_library(queueR queueR.h queueR.cpp)

add_executable(queueR_test queueR_test.cpp)
target_link_libraries(queueR_test queueR)