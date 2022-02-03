#include <iostream>
#include "examples/array_example.h"
#include "examples/parquet_example.h"



int main() {

	int64_example();
	print_parquet("/home/irshadcc/Documents/LearningProjects/ApacheArrow/resources/example.parquet");
	return 0 ; 
}