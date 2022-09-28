add_library(queueP queueP.cpp "queueP.h" "queueP_test.cpp")

add_executable(queueP_test queueP_test.cpp)
target_link_libraries(queueP_test queueP)