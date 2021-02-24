cmake_minimum_required(VERSION 3.10)

project(bfs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(bfs main.cpp)
add_library(lib SHARED ../nodes/node.cpp)

#add_executable(bfs test.cpp)
target_link_libraries(bfs lib)

#enable_testing()
#add_test(NAME Test COMMAND bfs)
#set_tests_properties(Test PROPERTIES PASS_REGULAR_EXPRESSION "OK")
