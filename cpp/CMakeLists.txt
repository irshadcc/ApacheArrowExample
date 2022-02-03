project(MyExample)
cmake_minimum_required(VERSION 3.17)

set(arrow_shared arrow)
set(parquet_shared parquet)

set(PARQUET_SOURCES,
	src/parquet/parquet_reader.cc)

set(EXAMPLE_SOURCES 
	src/example.cc 
	src/examples/array_example.cc 
	src/examples/parquet_example.cc
	src/api/row.cc
	src/parquet/parquet_reader.cc)

add_executable(example ${EXAMPLE_SOURCES}) 
target_link_libraries(example PRIVATE ${arrow_shared} ${parquet_shared})
