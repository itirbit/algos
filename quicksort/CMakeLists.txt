cmake_minimum_required(VERSION 3.10)

project(QuickSort)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(lib SHARED quicksort.cpp)

add_executable(QuickSort test.cpp)
target_link_libraries(QuickSort lib)

enable_testing()
add_test(NAME Test COMMAND QuickSort)
set_tests_properties(Test 
	PROPERTIES PASS_REGULAR_EXPRESSION "OK"
	)
