add_library(bitsetD bitsetD.h bitsetD.cpp)

add_executable(bitsetD_test bitsetD_test.cpp)

target_link_libraries(bitsetD_test bitsetD)