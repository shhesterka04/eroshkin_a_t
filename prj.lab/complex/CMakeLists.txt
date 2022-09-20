add_library(complex complex.cpp "complex.h" "complex_test.cpp")

add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test complex)