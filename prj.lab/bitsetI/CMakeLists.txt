add_library(bitsetI bitsetI.h bitsetI.cpp)

add_executable(bitsetI_test bitsetI_test.cpp)

target_link_libraries(bitsetI_test bitsetI bitset bitsetT bitsetD)