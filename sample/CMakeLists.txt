project(sample)
include_directories("../src")
add_executable(sample test.cpp)
target_link_libraries(sample JwPack)

