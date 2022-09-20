add_library(rational rational.cpp "rational.h" "rational_test.cpp")

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test rational)