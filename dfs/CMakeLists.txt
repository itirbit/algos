cmake_minimum_required(VERSION 3.10)

project(dfs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(dfs main.cpp)
add_library(lib SHARED ../nodes/node.cpp)

#add_executable(QuickSort test.cpp)
target_link_libraries(dfs lib)

#enable_testing()
#add_test(NAME Test COMMAND dfs)
#set_tests_properties(Test PROPERTIES PASS_REGULAR_EXPRESSION "OK")
