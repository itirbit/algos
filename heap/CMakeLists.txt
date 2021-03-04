cmake_minimum_required(VERSION 3.10)

project(heap)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(lib SHARED heap.cpp)

add_executable(heap test.cpp)
target_link_libraries(heap lib)

enable_testing()
add_test(NAME Test COMMAND heap)
set_tests_properties(Test 
	PROPERTIES PASS_REGULAR_EXPRESSION "OK"
	)
