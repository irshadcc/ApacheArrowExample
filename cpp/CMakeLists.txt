project(MyExample)

cmake_minimum_required(VERSION 3.17)

find_package(Arrow REQUIRED)

set(EXAMPLE_SOURCES 
	src/example.cc 
	src/examples/array_example.cc 
	src/examples/parquet_example.cc)
add_executable(example ${EXAMPLE_SOURCES})
target_link_libraries(example PRIVATE arrow_shared)